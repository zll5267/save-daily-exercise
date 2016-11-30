#include <iostream>

int main()
{
loc_a:
    std::cout<< "address is:" << &&loc_a << std::endl;
loc_b:
    std::cout<< "address is:" << &&loc_b << std::endl;
}
