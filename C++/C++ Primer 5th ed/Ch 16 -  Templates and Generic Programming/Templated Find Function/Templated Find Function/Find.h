// 
//   Author:           Lingurar Petru-Mugurel
//   Written:          2015-08-28 05:16 PM
//   Last updated:           ---
// 
//   Description:
//     Testing some templates concepts by writing my own version of 
//  the find algorithm.
// 
//   Bugs:
//     --- None ---
// 
//   TODO:
//     --- None --- 
// 
//   Notes:
//     Yeah, I know std::find returns an iterator.
//   I returned an lvalue just to test some concepts.
// 



#pragma once

#include <type_traits>


template <typename It, typename T>
auto Find(It beg, It end, const T item) 
    //-> decltype(*beg)     // decltype will give a lvalue reference

    // let's remove the reference..
    -> typename std::remove_reference<decltype(*beg)>::type
{
    while (beg != end)
    {
        if (*beg == item)
            return *beg;

        ++beg;
    }

    // -1 to not go out of range
    return *(beg - 1);      // dereferencing a pointer always gives an lvalue
 
}
