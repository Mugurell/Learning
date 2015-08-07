/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          27-Jul-15, 02:03 PM
 *  Last updated:     04 Aug 2015, 19:34:30:142 
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Execution:    ./...
 *
 *  Description:
 *  This class will just contain some functions used with the Quote clsses.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  Regarding the print_total function..:
 *  When a virtual function is called through a reference or pointer, the
 *  compiler generates code to decide at run time which function to call.
 *  The function that is called is the one that corresponds to the dynamic type
 *  of the object bound to that pointer or reference.
 *
********************************************************************************
*******************************************************************************/


#ifndef BOOK_SALES_USING_DERIVATE_CLASSES_FUNCTIONS_H
#define BOOK_SALES_USING_DERIVATE_CLASSES_FUNCTIONS_H


#include <iostream>
#include <vector>
#include <string>
#include <memory>       // std::shared_ptr

#include "Quote.h"
#include "Discounts.h"


class Person;

struct Functions {
    // Calculate and print the price for the given number of copies,
    // applying any discounts.
    static double print_total(const Quote &item, size_t n);


    // Calculate and print the total owed by a specific customer for all the
    // books_ he bought, applying any available discounts.
    static void print_total(const Person &person);
    static void print_books(const Person &person);
};



#endif //BOOK_SALES_USING_DERIVATE_CLASSES_FUNCTIONS_H
