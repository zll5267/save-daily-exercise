#ifndef A_H__
#define A_H__

class A
{
    friend class B;
private:
    class PA
    {
    public:
        static const int pa = 10;
    };
    static const int a = 100;
};

#endif
