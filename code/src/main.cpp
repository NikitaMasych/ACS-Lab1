#include "./../headers/stats.hpp"
#include "./../headers/timer.hpp"
#include "./../headers/warmup.hpp"

#include "./../templates/tests.ipp"

// Type, genesis and param value:

REGISTER_PARSE_TYPE(int,       2345,         7)
REGISTER_PARSE_TYPE(long long, 832943,       13)
REGISTER_PARSE_TYPE(float,     42431.293,    17.234)
REGISTER_PARSE_TYPE(double,    293843.32423, 349.71)

size_t Stats::test_amount{1};

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