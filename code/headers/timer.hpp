#pragma once

#include <chrono>

using namespace std::literals::chrono_literals;

class Timer {
public:
	Timer();
	long long timePassed();
	template<typename T>
	static long long measureCycleWithAssignment(const size_t& iterations){
		T a0{ std::numeric_limits<T>::max() };
		T a1{ std::numeric_limits<T>::max() / 3};
		T a2, a3, a4, a5, a6, a7, a8, a9;
		
		Timer timer;
		for (size_t i = 0; i != iterations; ++i) {
			a3 = a1;
			a1 = a0;
			a2 = a3;
			a4 = a1;
			a5 = a2;
			a6 = a4;
			a7 = a1;
			a8 = a6;
			a0 = a7;
			a9 = a0;
		}
		return timer.timePassed();
	}
private:
	std::chrono::system_clock::time_point start;
};