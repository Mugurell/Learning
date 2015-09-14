// 
//   Author:           Lingurar Petru-Mugurel                                   
//   Written:          2015-08-28 07:35 PM
//   Last updated:           ---
// 
//   Description:
//     Exercise 16.41: Write a version of sum with a return type that is
//   guaranteed to be large enough to hold the result of the addition.
// 
//   Bugs:
//     --- None ---
// 
//   TODO:
//     --- None --- 
// 
//   Notes:
//     --- 
//


#include <iostream>


template <typename T>
auto Sum(T lhs, T rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}


int main()
{
    short int a = 32767;        // max value for a short int
    short int b = 32767;

    auto total = Sum(a, b);

    std::cout << "\n\nThe sum of " << a << " and " << b << " is " << total 
              << "\n\n";

              return 0;
}