#include <iostream>
#include <string>
#include <cstdio>

#ifdef DEBUG_LEVEL
#error "not define debug level"
#endif

#define __NS2147483647  1
#define __NS2147483647L 2
#define NS_TEST_X(x) __NS##x
#define NS_TEST_Y(x) NS_TEST_X(x)

#if NS_TEST_Y(INT_FAST32_MAX) == __NS2147483647 && \
    NS_TEST_Y(INT_LEAST32_MAX) == __NS2147483647L && \
    NS_TEST_Y(INT32_MAX) == __NS2147483647L
#warning "OOOOKKKKKKK"
#endif

int fun()
{}

int main()
{
    char *name = 0;
    char *type = 0;
    if (!!name ^ !!type)
    {
        std::cout << "1^1 is true" << std::endl;
    }
    else
    {
        std::cout << "1^1 is false" << std::endl;
    }
    //std::string str = fun();
    int str;
    std::cout << str << std::endl;
    str = fun();
    std::cout << str << std::endl;

    for(int i = 0; i < 10; ++i)
    {
        std::cout << "i:" << i << std::endl;
        for(int j = 0; j < 10; ++j)
        {
            std::cout << "j:" << j << std::endl;
            break;
        }
    }

    char single_quote = '"';
    char slash = '\\';
    printf("%c, %c\n", single_quote, slash);
}

