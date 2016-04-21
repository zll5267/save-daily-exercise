#include <iostream>

template <typename c, typename f>
class IsSubClass {
    private:
        typedef char YesType;
        struct NoType {
            char padding[8];
        };

        static YesType subClassCheck(f*);
        static NoType subClassCheck(...);

        static c* t;
    public:
        static const bool value = sizeof(subClassCheck(t)) == sizeof(YesType);
};

class F {
};

class C : public F {
};

class O {
};

class only_forword_dec;

int main() {
    std::cout << " C is F's derived class: " << IsSubClass<C, F>::value << std::endl;
    std::cout << " O is F's derived class: " << IsSubClass<O, F>::value << std::endl;

    //std::cout << " only_forword_dec type sizeof: " << sizeof(only_forword_dec) << std::endl;
    std::cout << " only_forword_dec is F's derived class: " << IsSubClass<only_forword_dec, F>::value << std::endl;
}
