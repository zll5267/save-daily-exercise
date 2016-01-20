#include "iostream"

int main()
{
    wchar_t t[] = L"Hello 百度";
    std::cout << "length of t:" << wcslen(t) << std::endl;
    std::cout << "sizeof t:" << sizeof(t) << std::endl;
}
