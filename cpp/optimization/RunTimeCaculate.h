#ifndef _RUN_TIME_CACULATE_H__
#define _RUN_TIME_CACULATE_H__

#include <iostream>
#include <time.h>

class RunTimeCaculate
{
public:
    RunTimeCaculate(const char* t = NULL) : title(t) {
        clock_gettime(CLOCK_MONOTONIC, &startTime);
    }
    ~RunTimeCaculate() {
        timespec stopTime;
        clock_gettime(CLOCK_MONOTONIC, &stopTime);
        timespec diffTime;
        if ((stopTime.tv_nsec - startTime.tv_nsec) < 0) {
            diffTime.tv_sec = stopTime.tv_sec-startTime.tv_sec - 1;
            diffTime.tv_nsec = stopTime.tv_nsec - startTime.tv_nsec + 1000000000;
        } else {
            diffTime.tv_sec = stopTime.tv_sec-startTime.tv_sec;
            diffTime.tv_nsec = stopTime.tv_nsec - startTime.tv_nsec;
        }
        std::cout << title << " timespan is:" << diffTime.tv_sec << "s and " << diffTime.tv_nsec << "nsec." << std::endl;
    }

private:
    timespec startTime;
    const char* title;
};

#endif // _RUN_TIME_CACULATE_H__
