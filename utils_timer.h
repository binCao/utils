#ifndef UTILS_TIMER_H
#define UTILS_TIMER_H

#include <sys/time.h>

namespace utils {

class Timer 
{
public:
    Timer():
        _s(),
        _e()
    {
        gettimeofday(&_s, NULL);
        gettimeofday(&_e, NULL);
    }
    ~Timer() {}

    void start() {
        gettimeofday(&_s, NULL);
    }

    unsigned int calc_time_us() {
        gettimeofday(&_e, NULL);
        unsigned int diff_tm = (_e.tv_sec - _s.tv_sec) * 1000000 + (_e.tv_usec - _s.tv_usec);
        return diff_tm;
    }

    void restart() {
        gettimeofday(&_s, NULL);
    }

private:
    timeval _s;
    timeval _e;
};

}

#endif
