#include <iostream>

class AbstractC
{
    public:
        void print() = 0;
};

class ImplC
{
    public:
        void print() { std::cout << "hello world!" << std::endl; }
};

class Text : public AbstractC, public ImplC
{
};

int main()
{
    Text t;
    t.print();
}
