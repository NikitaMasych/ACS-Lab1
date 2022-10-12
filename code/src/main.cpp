#include "./../headers/stats.hpp"
#include "./../headers/timer.hpp"
#include "./../headers/warmup.hpp"

#include "./../templates/tests.ipp"

// Type, alpha and beta value:

REGISTER_PARSE_TYPE(int,       32823,        433)
REGISTER_PARSE_TYPE(long long, 832943,       1322)
REGISTER_PARSE_TYPE(float,     42431.293,    17.234)
REGISTER_PARSE_TYPE(double,    293843.32423, 349.71)

size_t Stats::test_amount{5};

int main(){
    warmupProcess();
    
    launchMultipleTests<int>();
    launchMultipleTests<long long>();
    launchMultipleTests<float>();
    launchMultipleTests<double>();

    Stats::calculateAverage();
    Stats::printDiagram();

    return 0;
}