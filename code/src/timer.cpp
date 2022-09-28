#include "./../headers/timer.hpp"

#include <chrono>
#include <iostream>

using namespace std::literals::chrono_literals;

Timer::Timer() {
	start = std::chrono::system_clock::now();
}

long long Timer::timePassed() {
	auto end = std::chrono::system_clock::now();
	return  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
};

long long Timer::measureEmptyBodyCycleDuration(const size_t& iterations) {
	Timer timer;
	for (size_t i = 0; i != iterations; ++i) {}
	return timer.timePassed();
}