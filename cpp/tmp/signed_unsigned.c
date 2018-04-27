#include <stdio.h>

int main() {
    printf("sizeof(int):%lu\n", sizeof(int));
    int ui = 0x7FFFFFFF;
    printf("ui:%d \n", ui);
    ++ui;
    printf("ui:%d \n", ui);
    printf("ui:%u \n", ui);
    printf("ui:0x%x \n", ui);
    //unsigned int uu = reinterpret_cast<unsigned>(ui);
    unsigned int uu = ui;
    printf("uu:%u \n", uu);

    unsigned int uu2 = 0x80000000;
    printf("uu2:%u \n", uu2);

    unsigned int uu3 = 4292835702;
    int i2 = -2131594;
    printf("uu3:%x \n", uu3);
    printf("i2:%x \n", i2);
    printf("uu3:%u \n", uu3);
    printf("i2:%d \n", i2);
    printf("===========================\n");
    int a = 0x7FFFFFFF;
    printf("a:%d\n", a);
    printf("a+1:%d\n", a+1);
    printf("(a + 1) / 1000 :%d\n", (a + 1) / 1000);
    unsigned b = a + 1;
    printf("b:0x%x\n", b);
    printf("b / 1000 :%d\n", b / 1000);

    unsigned int big = 4246145;
    unsigned int little = 6096;
    printf("little: 0x%x\n", little);
    printf("big: 0x%x\n", big);
    printf("little - big: 0x%x\n", little - big);
}
