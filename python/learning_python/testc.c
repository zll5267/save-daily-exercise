#include <Python.h>

int main()
{
    Py_Initialize();
    PyRun_SimpleString("x = 'brave' + 'sir robin'");
}
