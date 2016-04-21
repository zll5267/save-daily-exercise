#include "iostream"
//can't call the virtual method in the constructor
//or the unexpected result will come

class F
{
    public:
        F()
        {
            //print();
            callPrint();
        }
        void callPrint() {
            print();
        }
        virtual void print() = 0;//{ std::cout<< "F::print()" << std::endl;}
};

class C : public F
{
    public:
        void print() { std::cout << "C::print()" << std::endl; }
};

int main()
{
    C c;
}
