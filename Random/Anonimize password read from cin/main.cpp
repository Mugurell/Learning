/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          26 Aug 2015, 19:04:10:186
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  ---
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



#include <iostream>
#include <fstream>
#include <cctype>
#include <conio.h>

int main()
{
    std::cout << "\n\nUsername: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "\nPassword: ";
    char ch;
    std::string password;
    while ((ch = getch()) && isalnum(ch))
    {
        std::cout << "*";
        password.push_back(ch);
    }

    std::ofstream output_file;
    std::string output_file_name = name + ".txt";
    output_file.open(output_file_name, std::ofstream::out);

    if (!output_file)
        std::cerr << "\nThe file \"output_file\" could not be opened!\n";
    else
        output_file << "\n\nWelcome " << name << ", your password \""
                    << password << "\" was accepted!\n";

    output_file.close();

    return 0;
}