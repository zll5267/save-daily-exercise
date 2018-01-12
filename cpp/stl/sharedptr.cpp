#include <iostream>
#include <memory>
#include <list>

class MyTest {
public:
    MyTest(int ia):a(ia) {
        std::cout << "MyTest" << std::endl;
    }
    ~MyTest() {
        std::cout << "~MyTest" << std::endl;
    }

    int a;
};
std::list< std::shared_ptr<MyTest> > test_list;

int main() {
    std::shared_ptr<MyTest> test = std::make_shared<MyTest>(10);
    std::shared_ptr<MyTest> test2 = std::make_shared<MyTest>(10);
    test_list.push_back(test);
    //test_list.push_back(test2);
    test = NULL;
    test2 = NULL;
    std::cout << "size:" << test_list.size() << std::endl;
    //test_list.remove_if(
    //    [](std::shared_ptr<MyTest> t) {
    //        return t->a;
    //});
    std::cout << "size:" << test_list.size() << std::endl;
    for (auto  &it : test_list) {
        std::shared_ptr<MyTest> t = it;
        std::cout << "for begin, a:" << it->a << std::endl;
        if (it->a == 10) {
            test_list.remove(it);
            //break;
        }
        std::cout << "size:" << test_list.size() << std::endl;
        std::cout << "for end" << std::endl;
    }
    std::cout << "end" << std::endl;
    std::cout << "size:" << test_list.size() << std::endl;
}
