#pragma once

#include <vector>
#include <string>

class Stats {
public:
	Stats(const Stats&) = delete;
	Stats(Stats&&) = delete;
	Stats& operator=(const Stats&) = delete;
	static void write(std::string&&, std::string&&, double);
	static void printDiagram();
	static void calculateAverage();
	static double retrieveFastestPerformance();
	static size_t test_amount;
private:
	static std::vector<std::tuple<std::string, std::string, double>> stats;
};
