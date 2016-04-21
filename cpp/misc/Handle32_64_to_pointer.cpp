#include "iostream"

typedef unsigned int UInt32;
typedef unsigned long long UInt64;

typedef UInt32 Handle32;
typedef UInt64 Handle64;

class Value {
    public:
        Value(int value):v(value){}
        void printValue() {
            std::cout << "the value is:" << v << std::endl;
        }
    private:
        int v;
};

void gPrint(Handle64 obj) {
    //Value* pv = (Value*)(obj);
    std::cout << std::hex << "the obj value is: 0x" << obj << std::dec << std::endl;
    Value* pv = reinterpret_cast<Value*>(obj);
    pv->printValue();
}


int main() {
    Value v(100);
    std::cout << "the address of v is: " << &v << std::endl;
    gPrint((Handle64)&v);
}
