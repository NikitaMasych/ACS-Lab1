#pragma once
#include "./../headers/timer.hpp"
#include "./../headers/stats.hpp"
#include <iostream>
#include <functional>
#include <unordered_map>
#include <utility>

template<typename T>
struct TypeParseTraits;

#define REGISTER_PARSE_TYPE(X) template <> struct TypeParseTraits<X> \
    { static const char* name; } ; const char* TypeParseTraits<X>::name = #X;

template<typename T>
decltype(auto) initOperations() {
	std::function<T(const T&, const T&)> addition	    = [](const T& x, const T& y) {return x + y; };
	std::function<T(const T&, const T&)> substraction   = [](const T& x, const T& y) {return x - y; };
	std::function<T(const T&, const T&)> multiplication = [](const T& x, const T& y) {return x * y; };
	std::function<T(const T&, const T&)> division       = [](const T& x, const T& y) {return x / y; };

	std::unordered_map<char, std::function<T(const T&, const T&)>> operations;

	operations['+'] = addition;
	operations['-'] = substraction;
	operations['*'] = multiplication;
	operations['/'] = division;
	
	return operations;
}

template<typename T>
void test(std::pair<std::function<T(const T&, const T&)>, char> operation) {
	T a1, a2, a3, a4, genesis{ 127 };
	const size_t iterations{ 10000000 };
	Timer timer;
	for (size_t i = 0; i != iterations; ++i) {
		a1 = operation.first(genesis, 2);
		a2 = operation.first(a1, 3);
		a3 = operation.first(a2, 4);
		a4 = operation.first(a3, 5);
	}
	auto duration = timer.timePassed();
	auto cycleDuration = Timer::measureEmptyBodyCycleDuration(iterations);
	auto clearDuration = duration - cycleDuration;
	auto operations = iterations * 4;
	const auto milliToSec{ 1e3 };
	Stats::write(TypeParseTraits<T>::name, operation.second, (static_cast<double>(operations) / clearDuration) * milliToSec);
}

template<typename T>
void launchTests() {
	auto operations = initOperations<T>();
	test<T>(std::make_pair(operations['+'], '+'));
	test<T>(std::make_pair(operations['-'], '-'));
	test<T>(std::make_pair(operations['*'], '*'));
	test<T>(std::make_pair(operations['/'], '/'));
}