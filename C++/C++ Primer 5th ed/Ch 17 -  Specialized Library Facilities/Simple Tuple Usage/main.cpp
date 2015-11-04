/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          07 Oct 2015, 16:20:39:752
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  Exercise 17.1: Define a tuple that holds three int values and initialize the
 *  members to 10, 20, and 30.
 *  Exercise 17.2: Define a tuple that holds a string, a vector<string>,
 *  and a pair<string, int>
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  A tuple, by not being a container, involved really convoluted ways to
 *  iterate through it's elements. Here I've used a more direct approach.
 *
********************************************************************************
*******************************************************************************/



#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>


std::tuple<int, int, int> randomNumbers(void);
std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>>
    randomSomething(void);


int main()
{
    auto numbers = randomNumbers();
    auto something = randomSomething();

    std::cout << "\nLet's see " << std::tuple_size<decltype(numbers)>::value
        << " random numbers:";

    // get<>() use a template parameter to determine which element to be gotten.
    // Template parameters must be constexpr (compile-time const values).
    std::cout << "\n\t" << std::get<0>(numbers);
    std::cout << "\n\t" << std::get<1>(numbers);
    std::cout << "\n\t" << std::get<2>(numbers);


    std::cout << "\n\nAnd now, let's see some other.. random.. something..:\n";

    // first element in the tuple is a simple std::string
    std::cout << std::get<0>(something) << ' ';

    // second element is a std::vector<std::string>
    for (const std::string& each : std::get<1>(something))
    {
        std::cout << each << ' ';
    }

    // third element is a std::pair<std::string, int>
    std::cout << std::get<2>(something).first << ' ';
    std::cout << std::get<2>(something).second << '.';

    std::cout << "\n\nPretty cool, huh?\n";
    return 0;
}


std::tuple<int, int, int> randomNumbers(void)
{
    // Really no need for calling other functions..
    // Will initialize a tuple with random numbers myself.
    return std::tuple<int, int, int>{32,432,423};
}


std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>>
randomSomething(void)
{
    // Again, I'm good at random things..
    return std::make_tuple("Ana",
                           std::vector<std::string>{"are", "cinci"},
                           std::make_pair("mere -", 5));
}