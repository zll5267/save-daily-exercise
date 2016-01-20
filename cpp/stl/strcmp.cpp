#include <stdio.h>
#include <string.h>
int main()
{
    char *s = NULL;
    char *d = NULL;
    int res = strcmp(NULL, NULL);
    printf("res: %d\n", res);
    res = strcmp(s, d);
    printf("res: %d\n", res);
}
