#include "timer.hpp"

void Timer::start()
{
    timestamp1 = chrono::high_resolution_clock::now();
}


double Timer::stop()
{
    timestamp2 = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::duration<double, milli>>
        (timestamp2 - timestamp1).count();
}
