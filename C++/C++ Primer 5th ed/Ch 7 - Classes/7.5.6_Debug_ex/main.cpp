/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          28.05.2015 13:19
 *  Last updated:     28.05.2015 13:19
 *
 *  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic 
 *	 (g++ 5.1)		    
 *
 *  Execution:    ./...
 *
 *  Description:
 *  --- This is a description of what the program does ---
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Expected result:
 *  --- You can write here the execution command & the expected result --- 
 *
 *  Notes:
 *  --- Anything that stands out ---
 *  --- Or needs to be treated with special attention ---
 *
*******************************************************************************
******************************************************************************/


#include <iostream>
#include "Debug.cpp"

int main()
{
    constexpr Debug io_sub(false, true, false);     // debugging IO
    if (io_sub.any())    // eq to if true
        std::cout << "\nprint appropriate error messages.\n" << std::endl;

    constexpr Debug prod(false);        // no debugging during production
    if (!prod.any())     // eq to if false
        std::cout << "\nprint an error message\n" << std::endl;

    return 0;
}