#include <stdio.h>

struct array_test
{
    const char *name;
    int age;
};

static const struct array_test test[] = {
    [0] = { .name = "zhang", .age = 10 },
    [1] = { .name = "wang", .age = 22 }

};

int main()
{
    printf("test[%d]: name = %s, age = %d;\n", 0, test[0].name, test[0].age);
    printf("test[%d]: name = %s, age = %d;\n", 1, test[1].name, test[1].age);
    return 0;
}
