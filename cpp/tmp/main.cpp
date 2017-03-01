#include "stdio.h"

int main(int argc, const char* argv[])
{
    printf("&argc:%p\n", &argc);
    printf("buidin:%p\n", __builtin_frame_address(0));
}
