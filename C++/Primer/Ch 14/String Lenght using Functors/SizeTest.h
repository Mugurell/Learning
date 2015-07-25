/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          22-Jul-15, 09:43 PM
 *  Last updated:     22 Jul 2015, 22:54:30:388
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Execution:    ./...
 *
 *  Description:
 *  Function object class that tests whether the length of a given
 *  string matches a given bound.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  --- 
 *
********************************************************************************
*******************************************************************************/


#ifndef STRING_LENGHT_USING_FUNCTORS_SIZETEST_H
#define STRING_LENGHT_USING_FUNCTORS_SIZETEST_H


#include <string>


class SizeTest {
public:
    SizeTest(size_t min, size_t max);

    bool operator() (std::string word);

private:
    size_t min_size;
    size_t max_size;
};



#endif //STRING_LENGHT_USING_FUNCTORS_SIZETEST_H
