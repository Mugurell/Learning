/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          14 Jun 2015, 13:15
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
 *	 (g++ 5.1)		  -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *					  -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *					  -Wmissing-format-attribute -Wmissing-include-dirs  
 *					  -Wredundant-decls -Wswitch-default -Wswitch-enum 
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
#include <ctime>
#include <Functions.h>



int main()
{
    std::cout << "\n\tWelcome to the Great Date Calculator!"
              << "\n\nHere are your options:"
              << "\nA - Add days to a date;"
              << "\nB - Substract two dates;"
              << "\nC - Substract days from a date;"
              << "\nD - Find out in which day was/will be Christmas in a "
              << "specific year.";

    char choice;
    std::cin >> choice;



}
