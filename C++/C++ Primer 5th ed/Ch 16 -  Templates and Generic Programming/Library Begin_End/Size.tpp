/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10-Aug-15, 07:21 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  implementation file for the templated Size functions.
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



template <typename T, std::size_t N>
constexpr std::size_t Size(T (&)[N])     // don't need to name the array passed
                                         // by reference to not get
                                         // "unused variable" compile error
{
    return N;
}


template <typename Container>
constexpr std::size_t Size(const Container &cont)
{
    return cont.size();
}