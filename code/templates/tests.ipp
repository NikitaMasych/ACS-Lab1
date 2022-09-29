#pragma once

#include "./../headers/timer.hpp"
#include "./../headers/stats.hpp"

#include <unordered_map>
#include <string>
#include <limits>
#include <iostream>


template<typename T>
struct TypeParseTraits;

#define REGISTER_PARSE_TYPE(X, G) template <> struct TypeParseTraits<X> \
    {static std::string name; static X genesis;}; std::string TypeParseTraits<X>::name {#X};\
	X TypeParseTraits<X>::genesis {G};


template<typename T> 
inline T addition(const T& x, const T& y){
	return x + y;
}

template<typename T>
inline T substraction(const T& x, const T& y){
	return x - y;
}

template<typename T>
inline T multiplication(const T& x, const T& y){
	return x * y;
}

template<typename T>
inline T division(const T& x, const T& y){
	return x / y;
}

template<typename T>
decltype(auto) measure(decltype(addition<T>) func){
	T a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
	T genesis{ TypeParseTraits<T>::genesis };
	const size_t iterations{ 100000000 };

	Timer timer;
	for (size_t i = 0; i != iterations; ++i) {
		a0 = func(genesis, 11);
		a1 = func(a0, 3);
		a2 = func(a1, 6);
		a3 = func(a2, 7);
		a4 = func(a2, 19);
		a5 = func(a2, 5);
		a6 = func(a2, 14);
		a7 = func(a2, 15);
		a8 = func(a2, 9);
		a9 = func(a2, 21);
	}
	auto duration = timer.timePassed();

	auto auxilary_duration = Timer::measureCycleWithAssignment<T>(iterations);
	auto clear_duration = duration - auxilary_duration;
	auto operations_per_iteration { 10 };
	return std::make_pair(clear_duration, iterations * operations_per_iteration);
}

template<typename T>
void test(decltype(addition<T>) func, char operation) {
	auto [duration, operations] = measure<T>(func);
	const auto millisec_to_sec{ 1e3 };
	Stats::write(std::move(TypeParseTraits<T>::name), operation, (static_cast<double>(operations) / duration) * millisec_to_sec);
}

template<typename T>
void launchTests() {
	test<T>(addition<T>, '+');
	test<T>(substraction<T>, '-');
	test<T>(multiplication<T>, '*');
	test<T>(division<T>, '/');
}

template<typename T>
void launchMultipleTests() {
	for (size_t i = 0; i != Stats::test_amount; ++i){
		launchTests<T>();
	}
}