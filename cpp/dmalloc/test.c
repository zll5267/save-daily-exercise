#include <stdio.h>
#include "dmalloc.h"

int main() {
    void *p = malloc(10);
    printf("dmalloc test, p:%p\n", p);
    return 0;
}
