#include <iostream>

//declare can be repeated
int foo(int,int);
typedef int Int;
class bar;
extern int g_var;
using std::endl;
class foo
{
    friend class bar;
    friend class bar;
    public:
        static int i;
        //static int i;//in class delcare, the member can not be repeat.
        int j;
        //int j;//ditto
        int ff();
        //int ff();//ditto
};
//the second time define
extern int g_var;
typedef int Int;
using std::endl;
//definition
int bar;//var name can be same as class name(type)
class cff{};
struct bff{};
cff* p;
static int si;
enum Color{RED, GREEN, BLUE};
const double PI=3.1415926;
union Rep{};
void test(int p){};
class foo a;

int main()
{
    std::cout << "Hello World!" << std::endl;
}
