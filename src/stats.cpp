#include "./../headers/stats.hpp"
#include <tuple>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <math.h>

std::vector<std::tuple<const char*, char, double>> Stats::stats;

void Stats::write(const char* type, char operation, double duration) {
	auto line = std::make_tuple(type, operation, duration);
	stats.push_back(line);
}

std::string calculatePerformanceBar(const double rate, const int linearDiagramLength);

void Stats::printDiagram() {
	constexpr auto typeID{ 0 };
	constexpr auto operationID{ 1 };
	constexpr auto durationID{ 2 };
	const auto linearDiagramLength{ 40 };

	auto cmp = [](const auto& a, const auto& b) {
		return std::get<durationID>(a)<std::get<durationID>(b);
	};
	auto fastestDurationIT = std::max_element(stats.begin(), stats.end(), cmp);
	double fastestDuration = std::get<durationID>(*fastestDurationIT);

	for (const auto& line : stats) {
		auto type = std::get<typeID>(line);
		auto operation = std::get<operationID>(line);
		auto duration = std::get<durationID>(line);

		std::cout << std::setw(3) << operation;
		std::cout << std::setw(12) << type;
		std::cout << std::setw(15) << duration;
		
		auto rate =  duration / fastestDuration;
		std::cout << std::left << "  " << std::setw(linearDiagramLength + 5) <<
			calculatePerformanceBar(rate, linearDiagramLength) << std::right;
		std::cout << std::setw(10) << trunc(rate * 10000) / 100.0 << "%";
		std::cout << "\n";
	}
}

std::string calculatePerformanceBar(const double rate, const int linearDiagramLength) {
	int currentBarLength = round(linearDiagramLength * rate);
	std::string bar;
	if (currentBarLength == 0) bar = "";
	else bar.append(currentBarLength, '#');
	return bar;
}