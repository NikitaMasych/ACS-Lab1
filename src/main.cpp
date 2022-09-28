#include "./../headers/stats.hpp"
#include "./../headers/timer.hpp"
#include "./../headers/warmup.hpp"
#include "./../templates/tests.ipp"

int main(){
    warmUpProcess();

    launchTests<int>();
    launchTests<long long>();
    launchTests<float>();
    launchTests<double>();

    Stats::printDiagram();
    return 0;
}