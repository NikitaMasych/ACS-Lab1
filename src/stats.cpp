#include "./../headers/stats.hpp"

#include <tuple>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>


size_t Stats::test_amount{5};
std::vector<std::tuple<std::string, char, double>> Stats::stats;

enum{
	typeID,
	operationID,
	performanceID,
};

void Stats::write(std::string&& type, char operation, double performance) {
	stats.emplace_back(std::make_tuple(type, operation, performance));
}

std::string calculatePerformanceBar(const double& rate, const int& linearDiagramLength) {
	int currentBarLength = round(linearDiagramLength * rate);
	std::string bar;
	
	if (currentBarLength <= 0){
		std::cerr << "Too small rate";
		bar = "";
	}else{
		bar.append(currentBarLength, 'X');
	}
	return bar;
}

double Stats::retrieveFastestPerformance(){
	auto cmp = [](const auto& a, const auto& b) {
		return std::get<performanceID>(a)<std::get<performanceID>(b);
	};
	auto fastest_performance_it = std::max_element(stats.begin(), stats.end(), cmp);
	double fastest_performance = std::get<performanceID>(*fastest_performance_it);
	return fastest_performance;
}

void Stats::printDiagram() {
	const auto linear_diagram_length{ 40 };
	auto fastest_performance{ retrieveFastestPerformance()};
	
	size_t line_no = 1; 
	for (const auto& line : stats) {
		const auto& [type, operation, performance] = line;
		
		std::cout << std::setw(3) << operation;
		std::cout << std::setw(12) << type;
		std::cout << std::setw(15) << performance;
		
		auto rate = performance / fastest_performance;
		std::cout << std::left << "  " << std::setw(linear_diagram_length + 3);
		std::cout << calculatePerformanceBar(rate, linear_diagram_length) << std::right;
		std::cout << int(rate * 100) << "%";

		std::cout << '\n';
		const auto operation_per_type{4};
		if (line_no % operation_per_type == 0){ 
			std::cout << '\n';
		}
		++line_no;
	}
}

void Stats::calculateAverage(){
	decltype(Stats::stats) average_stats;
	const auto operation_types{ 4 };
	size_t records_per_type = test_amount * operation_types; 
	size_t amount_of_types = Stats::stats.size() / records_per_type;

	size_t offset = 0;
	for (size_t i = 0; i != amount_of_types; ++i){
		double add_speed, sub_speed, mul_speed, div_speed;
		const auto type_sample = std::get<typeID>(Stats::stats[offset]);

		auto average_add_speed {std::get<performanceID>(Stats::stats[offset])};
		auto average_sub_speed {std::get<performanceID>(Stats::stats[offset+1])};
		auto average_mul_speed {std::get<performanceID>(Stats::stats[offset+2])};
		auto average_div_speed {std::get<performanceID>(Stats::stats[offset+3])};
		offset += 4;

		for (size_t j = 1; j != test_amount; ++j){
			add_speed = std::get<performanceID>(Stats::stats[offset]);
			sub_speed = std::get<performanceID>(Stats::stats[offset+1]);
			mul_speed = std::get<performanceID>(Stats::stats[offset+2]);
			div_speed = std::get<performanceID>(Stats::stats[offset+3]);

			average_add_speed = (average_add_speed / 2.0 + add_speed / 2.0);
			average_sub_speed = (average_sub_speed / 2.0 + sub_speed / 2.0);
			average_mul_speed = (average_mul_speed / 2.0 + mul_speed / 2.0);
			average_div_speed = (average_div_speed / 2.0 + div_speed / 2.0);

			offset += 4;
		}

		average_stats.emplace_back(std::make_tuple(type_sample, '+', average_add_speed));
		average_stats.emplace_back(std::make_tuple(type_sample, '-', average_sub_speed));
		average_stats.emplace_back(std::make_tuple(type_sample, '*', average_mul_speed));
		average_stats.emplace_back(std::make_tuple(type_sample, '/', average_div_speed));
	}
	
	Stats::stats = average_stats;
}