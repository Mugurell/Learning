/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10-Aug-15, 03:55 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Exercise 16.5: Write a template version of the print function from § 6.2.4
 *  (p. 217) that takes a reference to an array and can handle arrays of any
 *  size and any element type.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  "Authors of templates should provide a header that contains the template
 *  definition along with declarations for all the names used in the class
 *  template or in the definitions of its members. Users of the template must
 *  include the header for the template and for any types used to instantiate
 *  that template."
 *  "Template programs should try to minimize the number of requirements
 *  placed on the argument types."
 *  Make sure the only place that includes <X>.tpp is the last line in <X>.h
 *
********************************************************************************
*******************************************************************************/



#ifndef PRINT_ARRAY_PRINT_H
#define PRINT_ARRAY_PRINT_H


// the nontype parameter will hold the size of the array
template<typename T, unsigned Size>
void Print(const T (&arr)[Size]);       // parenthesized the name because
                                        // don't want an array of references 


template<typename T>
void Print2(const T &array);


#include "Print.tpp"

#endif //PRINT_ARRAY_PRINT_H
