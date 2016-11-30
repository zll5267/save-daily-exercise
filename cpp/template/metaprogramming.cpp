#include <iostream>

template <int N>
int jiecheng() {
    return N * jiecheng<N-1>();
}

template <>
int jiecheng<1>() {
    return 1;
}

int main()
{
    std::cout<< "Hello world!" << std::endl;
    std::cout<<"5:" << jiecheng<5>() << std::endl;
}
