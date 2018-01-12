#include <iostream>

int main()
{
    const char *long_str = "ssss\
222222222";
    std::cout << long_str << ";" << std::endl;
    return 0;
}
