//
//  Author:           Lingurar Petru-Mugurel
//  Written:          23 Aug 2015  13:55:50
//  Last updated:           ---
//
//
//  Description:
//    Exercise 16.21: Write your own version of DebugDelete.
//  (A templated function in a non-templated class)
//
//  Bugs:
//    --- None ---
//
//  TODO:
//    --- None --- 
//
//  Notes:
//    --- 
//




#include "stdafx.h"

#include "DebugDelete.h"


int main()
{
    std::cout << "\nLet's say we have a unique_ptr to an int, to.. -> ";
    int nr;
    std::cin >> nr;
    std::cout << "to " << nr << ", yeah."
              << "\n\n.. Thing is I don't have any use for it right now..."
              << "\nSo I'm gonna go..\n\nBye now!\n";

    std::unique_ptr<int, DebugDelete> ptr(new int(nr), DebugDelete());

    return 0;
}

