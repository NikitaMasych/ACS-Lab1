#pragma once

#include "./../headers/timer.hpp"
#include "./../headers/stats.hpp"

#include <string>

template<typename T>
struct TypeParseTraits;


#define REGISTER_PARSE_TYPE(X, G, P) template <> struct TypeParseTraits<X> \
    {static std::string name; static X alpha; static X beta;}; std::string TypeParseTraits<X>::name {#X};\
	X TypeParseTraits<X>::alpha {G};\
	X TypeParseTraits<X>::beta {P};

#define TEST(OPERATION)\
{\
	[](){\
		T a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;\
		const T alpha { TypeParseTraits<T>::alpha };\
		const T beta   { TypeParseTraits<T>::beta};\
		const size_t iterations{ 100000000 };\
	\
		Timer timer;\
		for (size_t i = 0; i != iterations; ++i) {\
			a0 = alpha OPERATION beta;\
			a1 = alpha OPERATION beta;\
			a2 = alpha OPERATION beta;\
			a3 = alpha OPERATION beta;\
			a4 = alpha OPERATION beta;\
			a5 = alpha OPERATION beta;\
			a6 = alpha OPERATION beta;\
			a7 = alpha OPERATION beta;\
			a8 = alpha OPERATION beta;\
			a9 = alpha OPERATION beta;\
		}\
		auto duration = timer.timePassed();\
	\
		auto auxilary_duration = Timer::measureCycleWithAssignment<T>(iterations);\
		const auto clear_duration = duration - auxilary_duration;\
		const auto operations_per_iteration { 10 };\
		const auto operations = iterations * operations_per_iteration;\
		const auto millisec_to_sec{ 1e3 };\
		Stats::write(std::move(TypeParseTraits<T>::name), #OPERATION, (static_cast<double>(operations) / clear_duration) * millisec_to_sec);\
	}();\
}\

template<typename T>
void launchTests() {
	TEST(+)
	TEST(-)
	TEST(*)
	TEST(/)
}

template<typename T>
void launchMultipleTests() {
	for (size_t i = 0; i != Stats::test_amount; ++i){
		launchTests<T>();
	}
}