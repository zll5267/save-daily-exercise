#include <iostream>

#define IP_V6 "ipv6"
#define IP_V4 "ipv4"

#define IPV(N) IP_V##N

#define IP(n) #n

int main()
{
    std::cout << "ipv4:" << IPV(4) << std::endl;
    std::cout << "ipv6:" << IPV(6) << std::endl;
    std::cout << "ipv4:" << IP(4) << std::endl;


    return 0;
}
