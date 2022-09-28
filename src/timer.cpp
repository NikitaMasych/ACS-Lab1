#include <chrono>
#include <iostream>
#include "./../headers/timer.hpp"

using namespace std::literals::chrono_literals;

Timer::Timer() {
	start = std::chrono::system_clock::now();
}

long long Timer::timePassed() {
	end = std::chrono::system_clock::now();
	return  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
};

long long Timer::measureEmptyBodyCycleDuration(const size_t& iterations) {
	Timer timer;
	for (int i = 0; i != iterations; ++i) {}
	return timer.timePassed();
}