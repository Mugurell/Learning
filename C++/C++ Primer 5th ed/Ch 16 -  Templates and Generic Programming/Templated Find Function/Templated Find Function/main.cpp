// 
//   Author:           Lingurar Petru-Mugurel                                   
//   Written:          2015-08-28 05:05 PM
//   Last updated:           ---
// 
//   Description:
//     ----
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



#include "stdafx.h"

#include "Find.h"


int main()
{
    int x = 0;

    /* Initialize a vector of ints with 0 - 100. */
    std::vector<int> vec;
    do { vec.emplace_back(x); } while (++x != 100);


    /* Initialize a string with all the letters of the alphabet. */
    std::string str;
    x = 65;             // 'A' in ASCII
    while (x <= 90) {       // 'Z' in ASCII
        str.push_back(x);
        ++x;
    }

    x = 97;                  // 'a' in ASCII
    while (x <= 122) {       // 'z' in ASCII
        str.push_back(x);
        ++x;
    }


    /* Ask the user for values to search in our containers. */
    std::cout << "\n\nLet's say we have a vector of ints from 1 to 100"
              << "\nWhat number would you want to search for? -> ";

    int searched_nr;
    std::cin >> searched_nr;

    std::cout << "\n\nCool!"
              << "\nNow a letter of the alphabet? -> ";
    char searched_ch;
    std::cin >> searched_ch;


    /* Search for them. */
    int int_found = Find(vec.begin(), vec.end(), searched_nr);
    char ch_found = Find(str.begin(), str.end(), searched_ch);


    /* Print the results. */
    std::cout << "\n\n" << searched_nr << " was "
              << (int_found == searched_nr ? "found." : "not found.");

    std::cout << "\n\n" << searched_ch << " was "
              << (ch_found == searched_ch ? "found." : "not found.")
              << "\n\n\n";

    return 0;


}