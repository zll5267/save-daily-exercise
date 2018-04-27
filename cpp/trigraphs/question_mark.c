#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PATH "flash://connect?2323232"

void test(const char *path) {
    int len = strlen(path);
    char *str_offset = NULL;
    int offset = 0;

    for (int i = len - 2; i >= 0; --i) {
        if (path[i] == '?') {
            //printf("OK c:%c.\n", path[i]);
            str_offset = (char*)path + i + 1;
        }
    }

    printf("path:%s \n", path);
    printf("str_offset:%s \n", str_offset);

    offset = atoi(str_offset);
    printf("offset:%d\n", offset);
}
int main()
{
    test(PATH);
}
