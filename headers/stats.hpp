#pragma once
#include <vector>
#include <string>

class Stats {
public:
	Stats(const Stats&) = delete;
	Stats(Stats&&) = delete;
	Stats& operator=(const Stats&) = delete;
	static void write(std::string, char, double);
	static void printDiagram();
private:
	static std::vector<std::tuple<std::string, char, double>> stats;
};
