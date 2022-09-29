#include "./../headers/stats.hpp"
#include "./../headers/timer.hpp"
#include "./../headers/warmup.hpp"

#include "./../templates/tests.ipp"

// Type and genesis value:

REGISTER_PARSE_TYPE(int, 2345)
REGISTER_PARSE_TYPE(long long, 832943)
REGISTER_PARSE_TYPE(float, 42431.293)
REGISTER_PARSE_TYPE(double, 293843.32423)

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