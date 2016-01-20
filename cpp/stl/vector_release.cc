#include <vector>
#include <iostream>

class test
{
    public:
        test(int d):data(d){};
        ~test(){ std::cout << "~test with data:" << data << std::endl;}
    private:
        int data;
};

int main()
{
    std::vector<test> v;
    std::cout << "befor program, v's capacity:" << v.capacity() << std::endl;
    v.reserve(10);
    std::cout << "befor program, v's capacity:" << v.capacity() << std::endl;
    for( int i = 0; i < 2; ++i)
    {
        std::cout << "beforepush :" << i << std::endl;
        v.push_back(test(i));
        std::cout << "after push :" << i << std::endl;
    }
    std::cout << "at the end of the program!!!!"<< std::endl;
    return 0;
}
