#include "./../headers/stats.hpp"
#include "./../headers/timer.hpp"
#include "./../headers/warmup.hpp"
#include "./../templates/tests.ipp"

REGISTER_PARSE_TYPE(int);
REGISTER_PARSE_TYPE(long long);
REGISTER_PARSE_TYPE(float);
REGISTER_PARSE_TYPE(double);

int main(){
    warmUpProcess();

    launchTests<int>();
    launchTests<long long>();
    launchTests<float>();
    launchTests<double>();

    Stats::printDiagram();
    return 0;
}