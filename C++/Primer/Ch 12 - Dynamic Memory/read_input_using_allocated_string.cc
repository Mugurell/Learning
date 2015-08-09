/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 2 iulie 2015, 21:44:56 +0300
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
**  Exercise 12.26: Rewrite the program on page 481 -
**  (read_input_in_dinamic_char_array) using an allocator.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  The second part of 'read_input_in_dinamic_char_array' required to test the
**  program with different numbers of inputted chars vs what was allocated.
**  In this program:
**      - if the user inputs less chars than promosed - only the promised
**  number of chars will be stored
**      - if the user inputs more chars -> only promised number -1
**  will be stored.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <memory>       // allocator


int main()
{
    std::cout << "\nHow many letters will you type? -> ";
    std::size_t maxNumberOfChars;
    std::cin >> maxNumberOfChars;
    std::cin.ignore();

    std::cout << "\n\nStart typing!" << std::endl;
    std::allocator<char> alloc;
    char *dinamicCharPtr = alloc.allocate(maxNumberOfChars);
    char *backup = dinamicCharPtr;
    // char charBuffer;
    // while (std::cin.get(charBuffer))
    //     *dinamicCharPtr++ = charBuffer;
    std::cin.get(dinamicCharPtr, maxNumberOfChars);

    std::cout << "\n\nCool!"
              << "\nFrom what you said, I remember..:" << std::endl;

    dinamicCharPtr = backup;
    for (std::size_t count = 0; count++ != maxNumberOfChars; )
        std::cout << *dinamicCharPtr++;

    dinamicCharPtr = backup;
    alloc.destroy(dinamicCharPtr);
    alloc.deallocate(dinamicCharPtr, maxNumberOfChars);

    std::cout << ".\n\nPretty cool, huh?\n" << std::endl;
    return 0;
}
