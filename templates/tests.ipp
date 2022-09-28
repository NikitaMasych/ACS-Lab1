#pragma once
#include "./../headers/timer.hpp"
#include "./../headers/stats.hpp"
#include <iostream>
#include <functional>
#include <unordered_map>
#include <utility>

template<typename T>
decltype(auto) initOperations() {
	std::function<T(T&&, T&&)> addition		  = [](T&& x, T&& y) {return x + y; };
	std::function<T(T&&, T&&)> substraction   = [](T&& x, T&& y) {return x - y; };
	std::function<T(T&&, T&&)> multiplication = [](T&& x, T&& y) {return x * y; };
	std::function<T(T&&, T&&)> division       = [](T&& x, T&& y) {return x / y; };

	std::unordered_map<char, std::function<T(T&&, T&&)>> operations;

	operations['+'] = addition;
	operations['-'] = substraction;
	operations['*'] = multiplication;
	operations['/'] = division;
	
	return operations;
}

template<typename T>
void test(std::pair<std::function<T(T&&, T&&)>, char> operation) {
	T a1, a2, a3, a4, genesis{ 127 };
	const size_t iterations{ 10000000 };
	Timer timer;
	for (size_t i = 0; i != iterations; ++i) {
		a1 = operation.first(std::forward<T>(genesis), 2);
		a2 = operation.first(std::forward<T>(a1), 3);
		a3 = operation.first(std::forward<T>(a2), 4);
		a4 = operation.first(std::forward<T>(a3), 5);
	}
	auto duration = timer.timePassed();
	auto cycleDuration = Timer::measureEmptyBodyCycleDuration(iterations);
	auto clearDuration = duration - cycleDuration;
	auto operations = iterations * 4;
	const auto milliToSec{ 1e3 };
	Stats::write(typeid(T).name(), operation.second, (static_cast<double>(operations) / clearDuration) * milliToSec);
}

template<typename T>
void launchTests() {
	auto operations = initOperations<T>();
	test<T>(std::make_pair(operations['+'], '+'));
	test<T>(std::make_pair(operations['-'], '-'));
	test<T>(std::make_pair(operations['*'], '*'));
	test<T>(std::make_pair(operations['/'], '/'));
}