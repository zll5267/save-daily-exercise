#include <iostream>
#include <string>

class GValue
{
    public:
        static const std::string NAME;
};
//const std::string GValue::NAME = "zhang ll";

class GFunc
{
    public:
        static int* getString() {
            std::cout << "add of name:" << &GValue::NAME << ";value:0x"<< std::hex << *((int*)&GValue::NAME)<< std::endl;
            return (int*)&GValue::NAME;
        }
};

int* value = GFunc::getString();

//initialized here will cause the getString wrong.
const std::string GValue::NAME = "zhang ll";


int main()
{
    std::cout << "value:" << value << ";value at NAME:0x" << std::hex << *value << std::endl;
}
