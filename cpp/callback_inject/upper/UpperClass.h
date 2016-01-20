#ifndef UPPERCLASS_H__
#define UPPERCLASS_H__

class UpperClass
{
    public:
        UpperClass(int num);
        static void* Callback_Init();
        static void Init();
    private:
        static void* Create(int num);
        static void print(void* p);
        void print();
    private:
        int mNum;
};

#endif
