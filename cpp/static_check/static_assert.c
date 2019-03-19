#include <stdio.h>

//verify at compile time that certain restrictions are met.
#define STATIC_ASSERT(expression) \
    switch(0) {\
        case 0:\
        case expression:;\
    }

int main() {
    int a = 2;
    STATIC_ASSERT(sizeof(a)>6);
    printf("a:%d\n", a);
}

// error: duplicate case value
