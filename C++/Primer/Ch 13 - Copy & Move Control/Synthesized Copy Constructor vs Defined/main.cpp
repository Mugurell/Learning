/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:                ---
**  Last updated:           ---
**
**  Compilation:  g++ -std=c++14 -Wall -Wextra -pedantic -Wshadow
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
**                    -Wmissing-format-attribute -Wmissing-include-dirs
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum
**
**  Execution:    ./...
**
**  Description:
**  Exercise 13.14: Assume that numbered is a class with a default constructor
**  that generates a unique serial number for each object, which is stored in a
**  data member named mysn. Assuming numbered uses the synthesized copy-
**  control members and given the following function:
**          void f (numbered s) { cout << s.mysn << endl; }
**  what output does the following code produce?
**          numbered a, b = a, c = b;
**          f(a); f(b); f(c);
**  Exercise 13.15: Assume numbered has a copy constructor that generates a
**  new serial number. Does that change the output of the calls in the previous
**  exercise? If so, why? What output gets generated?
**  Exercise 13.16: What if the parameter in f were const numbered&?
**  Does that change the output? If so, why? What output gets generated?
**  Exercise 13.17: Write versions of numbered and f corresponding to the
**  previous three exercises and check whether you correctly predicted the
**  output.
**
**  Bugs:
**  The #define ex_fifteen/const_f_parameter funks my compilation.
**
**  TODO:
**  Fix the ifdef dependencies !!!!!!!!!
**
**  Notes:
**  Define ex_fifteen for the copy constructor to generate a new serial number.
**      Default is to use the synthesized copy constructor.
**  Define const_f_parameter so that the parameter in f will be
**  const Numbered&.
**
*******************************************************************************
******************************************************************************/



#include <iostream>

#include "Numbered.h"
#include "PrintFunction.h"


int main()
{
    Numbered one;
    std::cout << "\nFirst thing first, we should construct a new object:\n"
              << "One - ";
    f(one);
    std::cout << "\n\nNow let's create 3 new objects: a, b = a, c = b"
              << "\nand print them:" << std::endl;
    Numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
