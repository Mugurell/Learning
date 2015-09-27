/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10-Aug-15, 05:31 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Implementation file for the templated functions in Begin_end.h .
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



// versions of begin() and end() for regular arrays
template <typename T, std::size_t N>
inline T*Begin(T (&arr)[N])
{
    return arr;        // return a decay of the received parameter
}

template <typename T, std::size_t N>
inline T*End(T (&arr)[N])
{
    return arr + (N-1);     // N has 1 more element after the null terminator
                            // "one past the end"
}


// versions of begin() and end() for library containers
template<typename Container>
inline auto Begin(Container &cont) -> decltype(cont.begin())
{
    return cont.begin();
}

template<typename Container>
inline auto End(Container &cont) -> decltype(cont.end())
{
    return cont.end();
}
