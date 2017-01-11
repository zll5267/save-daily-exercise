#include "RunTimeCaculate.h"

#define R 1000
#define C 10

void sumArray(int dest[][C], int m, int n) {
    RunTimeCaculate tmp("sumArray");
    int i, j, sum;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            dest[i][j] = 0;
        }
    }
}

void sumArray2(int dest[][C], int m, int n) {
    RunTimeCaculate tmp("sumArray2");
    int i, j, sum;
    for (j = 0; j < n; ++j) {
        for (i = 0; i < m; ++i) {
            dest[i][j] = 0;
        }
    }
}

int main()
{
    int a[R][C];
    sumArray(a, R, C);
    sumArray2(a, R, C);
    return 0;
}
