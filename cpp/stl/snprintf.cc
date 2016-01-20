#include <cstdio>
#include <iostream>

int main()
{
    int n = snprintf(NULL, 0, "%u ", 10);
    std::cout << "n:" << n << std::endl;
}
