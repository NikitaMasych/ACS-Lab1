#include <random>
#include <vector>
#include "./../headers/warmup.hpp"

void warmUpProcess() {
	const size_t quantity{ 1000000 };
	std::vector<int> plainNumbers(quantity);
	for (auto& number : plainNumbers) {
		number = rand();
	}
	for (int i = 0; i != quantity; ++i) {
		plainNumbers[i] *= plainNumbers[quantity - i - 1];
	}
};