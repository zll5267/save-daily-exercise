#include "iostream"

template <int len>
void helper(int (&array)[len][len])
{
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            std::cout<< array[i][j] << std::endl;
        }
    }
}

int main()
{
    int array2[2][2] = {0};
    helper(array2);
    int array3[3][3] = {0};
    helper(array3);
}
