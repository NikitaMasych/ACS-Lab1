#include "./../headers/stats.hpp"
#include "./../headers/timer.hpp"
#include "./../headers/warmup.hpp"

#include "./../templates/tests.ipp"

REGISTER_PARSE_TYPE(int)
REGISTER_PARSE_TYPE(long long)
REGISTER_PARSE_TYPE(float)
REGISTER_PARSE_TYPE(double)

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