#ifndef TIMER_HPP
#define TIMER_HPP


#include <chrono>


using namespace std;

class Timer
{
    private:
        chrono::high_resolution_clock::time_point timestamp1;
        chrono::high_resolution_clock::time_point timestamp2;

    public:
        void set();
        double stop();
};


#endif
