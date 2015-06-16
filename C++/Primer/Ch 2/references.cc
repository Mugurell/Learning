#include <iostream>

int main()
{
    int i = 2, &r1 = i;
    double d = 3.14, &r2 = d;

    r2 = 3.1415;
    r2 = r1;
    std::cout << r2 << std::endl;

    int* ptr2i = &i;
    int*& ref2ptr = ptr2i;
    std::cout << ref2ptr << std::endl;

    const int &r = i;
    std::cout << "\n**Poti sa ai o const ref si catre un obiect normal" \
    		  << "\nnu neaparat sa fie constant!**\n" << std::endl;

    return 0;
}