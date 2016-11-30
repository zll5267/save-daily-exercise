#include "iostream"

template <int v>
struct Int2Type
{
    enum { value = v};
};

template <typename T, bool flag>
class CopyObject
{
private:
    T* copyObjectWithFlag(T* obj, Int2Type<true>)
    {
        std::cout << "CopyObject:: Int2Type<true>" << std::endl;
        T* result = obj->Clone();
        return result;
    }

    T* copyObjectWithFlag(T* obj, Int2Type<false>)
    {
        std::cout << "CopyObject:: Int2Type<false>" << std::endl;
        T* result = new T(*obj);
        return result;
    }

public:
    T* copyObject(T* obj)
    {
        return copyObjectWithFlag(obj, Int2Type<flag>());
    }
};

class CWithClone
{
public:
    CWithClone* Clone() {
        std::cout << "CWithClone::Clone" << std::endl;
        return new CWithClone();
    }
};

class CWithoutClone
{
public:
    CWithoutClone() {}
    CWithoutClone(const CWithoutClone&) {
        std::cout << "CWithoutClone::CWithoutClone" << std::endl;
    }
};

int main()
{
    CopyObject<CWithClone, true> objClone;
    CopyObject<CWithoutClone, false> objNoClone;

    CWithClone withClone;
    CWithoutClone withoutClone;

    objClone.copyObject(&withClone);
    objNoClone.copyObject(&withoutClone);

    return 0;
}
