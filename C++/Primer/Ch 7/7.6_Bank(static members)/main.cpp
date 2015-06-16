/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          28.05.2015 14:13
 *  Last updated:     28.05.2015 17:13
 *
 *  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic 
 *	 (g++ 5.1)		    
 *
 *  Execution:    ./...
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  Static member functions are not bound to any object; they do not have
 *  a this pointer. As a result, static member functions may not be declared
 *  as const, and we may not refer to this in the body of a static member.
 *  This restriction applies both to explicit uses of this and to implicit
 *  uses of this by calling a nonstatic member.
 *
*******************************************************************************
******************************************************************************/


#include <iostream>
#include "Account.cpp"

int main()
{
    std::cout << "\nThe current rate is " << Account::rate() << std::endl;
    return 0;
}