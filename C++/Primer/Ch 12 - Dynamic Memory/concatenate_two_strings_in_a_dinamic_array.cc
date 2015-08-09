/******************************************************************************
*******************************************************************************
**
**  hor:           Lingurar Petru-Mugurel
**  Written:       joi 2 iulie 2015, 17:08:11 +0300
**  Last updated:           ---
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Exercise 12.23: Write a program to concatenate two string literals, putting
**  the result in a dynamically allocated array of char. Write a program to
**  concatenate two library strings that have the same value as the literals
**  used in the first program.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  --- 
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <cstring>
#include <new>


int main()
{
    char stringLiteral1[20] {"Gheorghe"};
    char stringLiteral2[] {'H', 'a', 'g', 'i', '\0'};
    std::cout << "\nLet's say we have two string literals:\n\t"
              << stringLiteral1 << "\n\t\tand\n\t" << stringLiteral2 << ".\n"
              << "\nIf we're to concatenate them into a dinamically allocted\n"
              << "array of char, we'd get..:\n\t";
    char *dinamicCharArray = new char[20]();
    strcpy(dinamicCharArray, stringLiteral1);
    strcat(dinamicCharArray, " ");
    strcat(dinamicCharArray, stringLiteral2);
    std::cout << dinamicCharArray << ".\n\n";
    delete[] dinamicCharArray;

    std::cout << "Now if we're to concatenate two strings with the same"
              << "\nvalues, we'd get..\n\t";
    std::string string1 {"Gica "}, string2 {"Hagi"};
    std::string *dinamicStringArray = new std::string[1] {string1 + string2};
    std::cout << *dinamicStringArray << ".\n";
    delete[] dinamicStringArray;

    std::cout << "\n\nPretty cool, huh?\n" << std::endl;
    return 0;
}