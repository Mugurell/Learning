/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10-Aug-15, 01:25 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Implementation of the templated Find function
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  Because the file is a *.tpp file (not *.cpp) it should not be included by
 *  other build system operations.
 *  Make sure the only place that includes <X>.tpp is the last line in <X>.h
 *
********************************************************************************
*******************************************************************************/


template<typename InputIterator, typename Searched>
inline InputIterator Find(InputIterator begin, InputIterator end,
                          const Searched &item)
{
    while (begin != end) {      // between the sent range
        if (*begin == item)     // if there's one element == the searched one
            return begin;       // return the position of the first found
            ++begin;
    }
    return end;                 // else return end.
}
