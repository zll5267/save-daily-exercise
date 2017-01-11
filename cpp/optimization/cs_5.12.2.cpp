#include "RunTimeCaculate.h"

void clear_array(int *dest, int n) {
    RunTimeCaculate tmp("clear_array");
    int i;
    for (i = 0; i < n; ++i) {
        dest[i] = 0;
    }
    std::cout << "clear_array:i" << i << std::endl;
}

void clear_array_4(int *dest, int n) {
    RunTimeCaculate tmp("clear_array_4");
    int i;
    int limit = n -3;
    for (i = 0; i < limit; i += 4) {
        dest[i] = 0;
        dest[i+1] = 0;
        dest[i+2] = 0;
        dest[i+3] = 0;
    }
    for( i -= 4;i < n; ++i) {
        dest[i] = 0;
    }
    std::cout << "clear_array_4:i" << i << std::endl;
}

void write_read(int *src, int *dest, int n, const char* title)
{
    RunTimeCaculate tmp(title);
    int cnt = n;
    int val = 0;
    while (cnt--) {
        *dest = val;
        val = (*src) + 1;
    }
}

int main()
{
    int a[1000];
    clear_array(a, 1000);
    clear_array_4(a, 1000);

    write_read(&a[0], &a[1], 10000, "src diff with dest");
    write_read(&a[0], &a[0], 10000, "src same as dest");
    return 0;
}
