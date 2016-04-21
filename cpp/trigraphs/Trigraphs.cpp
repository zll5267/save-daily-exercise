/*


Before any other processing takes place, each occurrence of one of the following sequences of three characters
(“trigraph sequences”) is replaced by the single character indicated in Table 1.

    ----------------------------------------------------------------------------
    | trigraph | replacement | trigraph | replacement | trigraph | replacement |
    ----------------------------------------------------------------------------
    | ??=      | #           | ??(      | [           | ??<      | {           |
    | ??/      | \           | ??)      | ]           | ??>      | }           |
    | ??’      | ˆ           | ??!      | |           | ??-      | ˜           |
    ----------------------------------------------------------------------------


   */

#include "iostream"

int main() {
    std::cout << "??=" << std::endl;
    std::cout << "\?\?=" << std::endl;
    return 0;
}
