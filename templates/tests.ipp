#pragma once

#include "./../headers/timer.hpp"
#include "./../headers/stats.hpp"

#include <unordered_map>
#include <string>

template<typename T>
struct TypeParseTraits;

#define REGISTER_PARSE_TYPE(X) template <> struct TypeParseTraits<X> \
    {static std::string name;}; std::string TypeParseTraits<X>::name {#X};

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
	T alpha, beta, gamma, omega, genesis{ 125 };
	const size_t iterations{ 10000000 };

	Timer timer;
	for (size_t i = 0; i != iterations; ++i) {
		alpha = func(genesis, 2);
		beta  = func(alpha,   3);
		gamma = func(beta,    4);
		omega = func(gamma,   5);
	}
	auto duration = timer.timePassed();

	auto cycle_duration = Timer::measureEmptyBodyCycleDuration(iterations);
	auto clear_duration = duration - cycle_duration;
	auto operations_per_iteration { 4 };
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