// 
//   Author:           Lingurar Petru-Mugurel
//   Written:          2015-08-23 02:00 PM
//   Last updated:           ---
// 
//   Description:
//    Exercise 16.21: Write your own version of DebugDelete.
//  (A templated function in a non-templated class)
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
// 
// 


#pragma once

#include "stdafx.h"


class DebugDelete
{
    std::ostream &os;

public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) { }
    
    template<typename T>
    void operator()(T *p) 
        { 
            os << "\n\t**Deleting the shared_ptr.. **\n"; 
            delete p; 
        }
    
};
