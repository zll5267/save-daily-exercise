#include <iostream>
#include <cstdio>
#include <time.h>
#include <unistd.h>

using namespace std;

timespec DiffTime(timespec start, timespec end)
{
    timespec temp;
    if ((end.tv_nsec - start.tv_nsec) < 0) {
        temp.tv_sec = end.tv_sec-start.tv_sec - 1;
        temp.tv_nsec = end.tv_nsec - start.tv_nsec + 1000000000;
    } else {
        temp.tv_sec = end.tv_sec-start.tv_sec;
        temp.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
    return temp;
}

int main() {
    struct timespec startTime;
    clock_gettime(CLOCK_MONOTONIC, &startTime);
    cout << "sysconf(_SC_CLK_TCK):" << sysconf(_SC_CLK_TCK) << endl;

    clockid_t clocks[] = {
        CLOCK_REALTIME,
        CLOCK_MONOTONIC,
        CLOCK_PROCESS_CPUTIME_ID,
        CLOCK_THREAD_CPUTIME_ID,
        (clockid_t)-1
    };

    for (int i = 0; clocks[i] != (clockid_t)-1; ++i) {
        struct timespec res;
        int ret = clock_getres(clocks[i], &res);
        if (ret)
            perror("clock_getres");
        else
            cout << "clock_getres clockid:" << clocks[i] << "; sec:" << res.tv_sec << "; nsec:" << res.tv_nsec << endl;
    }

    for (int i = 0; clocks[i] != (clockid_t)-1; ++i) {
        struct timespec res;
        int ret = clock_gettime(clocks[i], &res);
        if (ret)
            perror("clock_gettime");
        else
            cout << "clock_gettime clockid:" << clocks[i] << "; sec:" << res.tv_sec << "; nsec:" << res.tv_nsec << endl;
    }

    struct timespec stopTime;
    clock_gettime(CLOCK_MONOTONIC, &stopTime);


    timespec diffTime = DiffTime(startTime, stopTime);
    cout << "timespan is:" << diffTime.tv_sec << "s and " << diffTime.tv_nsec << "nsec." << endl;
    return 0;
}

