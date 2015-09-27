/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          23 Sep 2015, 13:26:29:102
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  Exercise 16.47: Write your own version of the flip function and test it by
 *  calling functions that have lvalue and rvalue reference parameters.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  The template function Flip rceives 3 arguments:
 *      - a pointer to a function
 *      - 2 other arguments of possible different types. Because this 2
 *      arguments are declared as rvalue ref, through collapsing with the
 *      deduced types - T1 and T2, they will preserve all the type information
 *      of the arguments sent to it (constness, lvalue/rvalue/ regular nonref).
 *
 *  The 2 arguments are then sent through forwarding to another function.
 *  std::forward, unlike std::move must always be explicitly templated and will
 *  always return a rvalue reference to that explicit argument type:
 *      - if the underlying type is regular nonref -> will return T
 *      - if the underlying type is lvalue ref.    -> will return T& &&
 *                                                   which collapses into T&
 *      - if the underlying type is rvalue ref.    -> will return T&& &&
 *                                                   Which collapses into T&&
 *  Because of this, again all the type information will be preserved.
 *
 *  By combining the first template function with forwarding we ensure all the
 *  type information is preserved across 2 passings of the arguments.
 *  Still, cannot forward something more than once, though,
 *  because that makes no sense.
 *  Forwarding means that you're potentially moving the argument all the way
 *  through to the final caller, and once it's moved it's gone, so you cannot
 *  then use it again.
 *
********************************************************************************
*******************************************************************************/



#include <iostream>
#include <utility>      // std::forward, std::move


template<typename F, typename T1, typename T2>
void Flip(F func, T1 &&arg1, T2 &&arg2)
{
    //func(arg1, arg2);
    func(std::forward<T1>(arg1), std::forward<T2>(arg2));
}


void f(int &&a, int &&b) { std::cout << ++a << " and " << ++b; }
void g(int &a, int &b) { std::cout << ++a << " and " << ++b; }

int main()
{
    using namespace std;

    cout << "Passing two literals - 13 and 24 we get:\n\t";
    Flip(f, 13, 24);    // g has parameters that take int lvalue ref
                        // can't init it with an rvalue
                        // for that, it would have to be const int& or int&&

    cout << "\n\nPassing two integers - a(13) and b(24) we get:\n\t";
    int a{13}, b{24};
    Flip(g, a, b );
    cout << "\nAnd back to main we have: " << a << " and " << b;

    cout << "\n\nPassing two lvalue refs to a(13) and b(24) we get:\n\t";
    a = 13; b = 24;
    int &refa = a; int &refb = b;
    Flip(g, refa, refb );
    cout << "\nAnd back to main we have: " << a << " and " << b;

    return 0;
}
