#include <iostream>
#include <list>
#include <memory>

class Test {
public:
    Test() {
        std::cout << "count:" << count << ",this:" << this << std::endl;
        count++;
    };
    ~Test() {
        if(count)
            std::cout << "count:" << count << ",this:" << this << std::endl;
    }
private:
    int count;
};

int main() {

    std::list<std::shared_ptr<Test>> list;
    for(int i = 0; i < 1000; ++i) {
        std::shared_ptr<Test> ptr = std::make_shared<Test>();
        //list.push_back(ptr);
    }

    //std::list<Test*> list;
    //for(int i = 0; i < 1000; ++i) {
    //    Test* p = new Test();
    //    list.push_back(p);
    //}

    return 0;
}
