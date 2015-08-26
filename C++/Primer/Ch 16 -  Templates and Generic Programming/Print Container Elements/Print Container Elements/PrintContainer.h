// 
//   Author:           Lingurar Petru-Mugurel
//   Written:          2015-08-22 12:30 PM
//   Last updated:           ---
// 
//   Description:
//    Exercise 16.19: Write a function that takes a reference to a container and
//  prints the elements in that container.Use the container’s size_type and
//  size members to control the loop that prints the elements.
//    Exercise 16.20: Rewrite the function from the previous exercise to use
//  iterators returned from begin and end to control the loop.
// 
//   Bugs:
//     --- None ---
// 
//   TODO:
//     --- None --- 
// 
//   Notes:
//     Of course that I could've used a ranged for loop to print the elements
//  in function Print19. I've wanted to make use of the scope resolution
//  operator. Remember that by default the scope resolution operator will not
//  give a type, but it will try to access a static member.
//  If in a template I'd use class    - default scope operator behaviour;
//  If in a template I'd use template - scope operator will return a type!
// 


#pragma once


template <typename C>
void Print19(C& container)
{
    std::stable_sort(container.begin(), container.end());
    using pos = C::size_type;       // scope operator will return a type!
    pos elementsNo = container.size();
    while (--elementsNo >= 0)       // will overflow!
    {
        std::cout << "\n\t" << container.at(elementsNo);
        if (elementsNo == 0)
            break;
    }
}


template <typename C>
void Print20(C& container)
{
    //std::stable_sort(container.begin(), container.end());
    for (auto beg = container.begin(), end = container.end(); beg != end; ++beg)
    {
        std::cout << "\n\t" << *beg;
    }
}
