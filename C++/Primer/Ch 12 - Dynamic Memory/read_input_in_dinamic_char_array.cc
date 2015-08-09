/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 2 iulie 2015, 17:34:56 +0300
**  Last updated:           ---
**
**  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Exercise 12.24: Write a program that reads a string from the standard input
**  into a dynamically allocated character array. Describe how your program
**  handles varying size inputs. Test your program by giving it a string of 
**  data that is longer than the array size you’ve allocated.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  Will 'remember' only maxNumberOfLetters even if the user types more.
**
**  Notes:
**  In this implementation, if the user is cheating and enters more characters
**  than he said he will, they will just be ignored.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <new>


int main()
{
    std::cout << "\nHow many letters will you type? -> ";
    std::size_t maxNumberOfLetter;
    std::cin >> maxNumberOfLetter;
    std::cin.ignore();

    char *dinamicCharArray = new char[maxNumberOfLetters];
    std::cout << "\n\n\tStart typing!" << std::endl;
    std::cin.get(dinamicCharArray, maxNumberOfLetters);

    std::cout << "\n\nI remember you typing..\n" << dinamicCharArray;
    delete[] dinamicCharArray;

    std::cout << "\n\nPretty cool, huh?\n" << std::endl;
    return 0; 
}