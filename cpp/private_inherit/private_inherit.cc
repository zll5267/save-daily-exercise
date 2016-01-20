#include <iostream>
class Data
{
    private:
        Data(){};
};

class Value:public Data
{
    public:
        Value(){};
        void operator ()(){ std::cout << "Hello World" << std::endl; }
};


int main()
{
    Value v;
    v();
    return 0;
}
