#pragma once

#include "./../headers/timer.hpp"
#include "./../headers/stats.hpp"

#include <string>

template<typename T>
struct TypeParseTraits;


#define REGISTER_PARSE_TYPE(X, G, P) template <> struct TypeParseTraits<X> \
    {static std::string name; static X genesis; static X param;}; std::string TypeParseTraits<X>::name {#X};\
	X TypeParseTraits<X>::genesis {G};\
	X TypeParseTraits<X>::param {P};
	
#define TEST(OPERATION)\
{\
	T a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;\
	const T genesis { TypeParseTraits<T>::genesis };\
	const T param   { TypeParseTraits<T>::param};\
	const size_t iterations{ 100000000 };\
\
	Timer timer;\
	for (size_t i = 0; i != iterations; ++i) {\
		a0 = genesis OPERATION param;\
		a1 = a0 OPERATION param;\
		a2 = a1 OPERATION param;\
		a3 = a2 OPERATION param;\
		a4 = a3 OPERATION param;\
		a5 = a4 OPERATION param;\
		a6 = a5 OPERATION param;\
		a7 = a6 OPERATION param;\
		a8 = a7 OPERATION param;\
		a9 = a8 OPERATION param;\
	}\
	auto duration = timer.timePassed();\
\
	auto auxilary_duration = Timer::measureCycleWithAssignment<T>(iterations);\
	const auto clear_duration = duration - auxilary_duration;\
	const auto operations_per_iteration { 10 };\
	const auto operations = iterations * operations_per_iteration;\
	const auto millisec_to_sec{ 1e3 };\
	Stats::write(std::move(TypeParseTraits<T>::name), #OPERATION, (static_cast<double>(operations) / clear_duration) * millisec_to_sec);\
}\

template<typename T>
void launchTests() {
	TEST(+, add);
	TEST(-, sub);
	TEST(*);
	TEST(/);
}
operation_add(){}

template<typename T>
void launchMultipleTests() {
	for (size_t i = 0; i != Stats::test_amount; ++i){
		launchTests<T>();
	}
}