#include <iostream>

void setarray(int p[])
{
    p[0] = 10;
    p[1] = 11;
    p[2] = 12;
    p[3] = 13;
}

int sj;

void seti( int* p)
{
    sj = *p;
}

int init()
{
    int t = 10;
    seti(&t);
    std::cout << "called in static function!" << std::endl;
    return t;
}

int si = init();

int main()
{
    int p[4] = { 0 };
    std::cout << "before:" ;
    for(int i = 0; i < 4; ++i)
    {
        std::cout << p[i] << ",";
    }
    std::cout << std::endl;

    setarray(p);

    std::cout << "after:" ;
    for(int i = 0; i < 4; ++i)
    {
        std::cout << p[i] << ",";
    }
    std::cout << std::endl;

    bool a = true;
    bool b = false;
    bool c = true;
    if (a && b || c)
        std::cout << "true" << std::endl;

    std::cout << "sj is:" << sj << std::endl;
}
