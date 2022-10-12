#include <random>
#include <vector>

void warmupProcess() {
	const size_t quantity{ 100000000 };
	std::vector<int> plain_numbers(quantity);
	for (auto& number : plain_numbers) {
		number = rand();
	}
	for (int i = 0; i != quantity; ++i) {
		plain_numbers[i] *= plain_numbers[quantity - i - 1];
	}
};