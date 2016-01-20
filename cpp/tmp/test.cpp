#include <iostream>
#include <string>


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
}

