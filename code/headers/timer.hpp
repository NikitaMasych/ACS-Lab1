#pragma once

#include <chrono>

using namespace std::literals::chrono_literals;

class Timer {
public:
	Timer();
	long long timePassed();
	template<typename T>
	static long long measureCycleWithAssignment(const size_t& iterations){
		T value{ std::numeric_limits<T>::max() };
		T a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
		Timer timer;
		for (size_t i = 0; i != iterations; ++i) {
			a0 = value;
			a1 = value;
			a2 = value;
			a3 = value;
			a4 = value;
			a5 = value;
			a6 = value;
			a7 = value;
			a8 = value;
			a9 = value;
		}
		return timer.timePassed();
	}
private:
	std::chrono::system_clock::time_point start;
};