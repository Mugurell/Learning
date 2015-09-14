//
//  Author:           Lingurar Petru-Mugurel
//  Written:          22 Aug 2015  12:12:38
//  Last updated:           ---
//
//
//  Description:
//    Exercise 16.19: Write a function that takes a reference to a container and
//  prints the elements in that container.Use the container’s size_type and
//  size members to control the loop that prints the elements.
//    Exercise 16.20: Rewrite the function from the previous exercise to use
//  iterators returned from begin and end to control the loop.
//
//  Bugs:
//    --- None ---
//
//  TODO:
//    --- None --- 
//
//  Notes:
//    Use Print19(container) or Print20(container).
//


#include "stdafx.h"

#include "PrintContainer.h"


int main()
{
    std::cout << "\nI have an empty std::vector."
              << "\nPlease help me to fill it with some ints.\n\t -> ";

    std::vector<int> vInt;
    int newNr;
    while (std::cin >> newNr) 
        vInt.emplace_back(newNr);

    if (vInt.size() == 0)
        std::cout << "\n\nYou have no heart!\n\nBye!\n";

    Print19(vInt);

    std::cout << "\n\n";

    return 0;
}

