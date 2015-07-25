/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          23-Jul-15, 03:36 PM
 *  Last updated:     23 Jul 2015, 19:40:42:065 
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Execution:    ./...
 *
 *  Exercise 14.42: Using library function objects and adaptors, define an
 *  expression to
 *  (a) Count the number of values that are greater than 1024
 *  (b) Find the first string that is not equal to pooh
 *  (c) Multiply all values by 2
 *  Exercise 14.43: Using library function objects, determine whether a given
 *  int value is divisible by any element in a container of ints.
 *  Exercise 14.43: Using library function objects, determine whether a given
 *  int value is divisible by any element in a container of ints.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  ******* About static functions: **********
 *  Like static member variables, static member functions are not attached to
 *  any particular object.
 *  Because static member functions are not attached to a particular object,
 *  they can be called directly by using the class name and the scope operator.
 *  Like static member variables, they can also be called through objects of the
 *  class type, though this is not recommended.
 *  Static member functions have two interesting quirks worth noting.
 *  First, because static member functions are not attached to an object, they
 *  have no this pointer! This makes sense when you think about it -- the this
 *  pointer always points to the object that the member function is working on.
 *  Static member functions do not work on an object so the this pointer is
 *  not needed.
 *  Second, static member functions can only access static member variables.
 *  They can not access non-static member variables. This is because non-static
 *  member variables must belong to a class object, and static member functions
 *  have no class object to work with!
 *  Because all of the members belong to the class, and the class is accessible
 *  from anywhere in the program, it’s essentially the equivalent of declaring a
 *  global variable of the class type. And this is dangerous because one piece
 *  of code can change the value of the global variable and end up breaking
 *  another piece of seemingly unrelated code.
********************************************************************************
*******************************************************************************/


#ifndef LIBRARY_FUNCTION_OBJECTS_EXERCISE_H
#define LIBRARY_FUNCTION_OBJECTS_EXERCISE_H


#include <vector>


class Exercise {
public:
    // (a) Count the number of values that are greater than 1024
    static void A(const int);

    // (b) Find the first string that is not equal to pooh
    static void B(void);

    // (c) Multiply all values by 2
    static void C(const int);

    // (d) Test if the given int is divisible by any integer from a vector
    static void D(const int);
};



#endif //LIBRARY_FUNCTION_OBJECTS_EXERCISE_H
