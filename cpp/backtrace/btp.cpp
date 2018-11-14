/**
  * btp   backtrace print
  */
#include <iostream>
#include <execinfo.h>
#include <stdlib.h>

using std::cout;

void print_trace(void)
{
    void *array[10];
    size_t size;
    char **strings;
    size_t i;

    size = backtrace(array, 10);
    strings = backtrace_symbols(array, size);
    if (NULL == strings)
    {
        std::cout << "backace_symbols" << std::endl;
        return;
    }
    std::cout << "Obtained " << size << " stack frames." << std::endl;

    for(i = 0; i < size; ++i)
    {
        std::cout << i << ":" << strings[i] << std::endl;
    }

    free(strings);
    strings = NULL;
}

int f1(int v)
{
    print_trace();
    cout << "f1 param is:" << v << std::endl;
}

int f2(int v)
{
    cout << "f2 param is:" << v << std::endl;
    f1(v);
}

int f3(int v)
{
    cout << "f3 param is:" << v << std::endl;
    f2(v);
}

int f4(int v)
{
    cout << "f4 param is:" << v << std::endl;
    f3(v);
}

int main()
{
    f4(10);
    return 0;
}
