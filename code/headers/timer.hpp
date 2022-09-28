#pragma once

#include <chrono>

using namespace std::literals::chrono_literals;

class Timer {
public:
	Timer();
	long long timePassed();
	static long long measureEmptyBodyCycleDuration(const size_t& iterations);
private:
	std::chrono::system_clock::time_point start;
};