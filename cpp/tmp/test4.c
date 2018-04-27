#include <stdio.h>

int main()
{
    const char *str = "443";
    const char *p = str;
    double n = 0;

    while (*p) {
        printf("line:%d, n:%f p:%c\n", __LINE__, n, *p);
        n = (n * 10.0) + (*p++ - '0');
    }
    printf("line:%d, n:%f \n", __LINE__, n);

    p = str; n = 0;
    while (*p) {
        printf("line:%d, n:%f \n", __LINE__, n);
        n = (n * 10.0) + (*p - '0');
        p++;
    }
    printf("line:%d, n:%f \n", __LINE__, n);
    return 0;
}
