#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func1() {
    char hw[] = "Hello func1";
    char buffer[32];
    memset(buffer, 0, sizeof(buffer));
    memcpy(buffer, hw, sizeof(hw));
    printf("%s\n", buffer);
}

int main() {
    func1();
    printf("hello world!\n");
}
