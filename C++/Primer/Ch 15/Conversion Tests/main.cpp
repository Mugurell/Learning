/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          31 Jul 2015, 18:55:18:711
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Description:
 *  Exercise 15.18: Given the classes from page 612 and page 613, and assuming
 *  each object has the type specified in the comments, determine which of these
 *  assignments are legal. Explain why those that are illegal aren't allowed.
 *      Base *p = &d1;  // d1 has type Pub_Derv                 - legal
 *      p = &d2;        // d2 has type Priv_Derv                - illegal
 *      p = &d3;        // d3 has type Prot_Derv                - illegal
 *      p = &dd1;       // dd1 has type Derived_from_Public     - legal
 *      p = &dd2;       // dd2 has type Derived_from_Private    - illegal
 *      p = &dd3;       // dd3 has type Derived_from_Protected  - illegal
 *
 *  Why? : User code may use the derived-to-base conversion only if the derived
 *  inherits publicly. User code may not use the derived-to-base conversion
 *  if it inherits using protected or private access specifiers.
 *  (For ex. if the inherited members were put in the private section of the
 *  derived, if the "conversion" was successful, how would a user access the
 *  public member of the base, if that is in the private section?)
 *---------------
 *
 * Exercise 15.19: Assume that each of the classes from page 612 and page
 * 613 has a member function of the form:
 *          void memfcn(Base &b) { b = *this; }
 * For each class, determine whether this function would be legal.
 *
 *      Answer:
 * Member functions and friends of D can use the conversion to B regardless
 * of how D inherits from B. The derived-to-base conversion to a direct base
 * class is always accessible to members and friends of a derived class.
 * (Even members that are protected/private can be accessed by other class
 * members or class's friends.)
 * Hence, the 3 below are all legal:
 *
 *          Pub_Derv    --  legal
 *          Priv_Derv   --  legal
 *          Prot_Derv   --  legal
 *
 *  Member functions and friends of classes derived from D may use the
 *  derived-to-base conversion if D inherits from B using either public or
 *  protected, in which case D's members are available to it's derivate.
 *  Such code may not use the conversion if D inheritsprivately from B.Hence:
 *          Derived_from_Public    --  legal
 *          Derived_from_Private   --  illegal
 *          Derived_from_Protected --  legal
 *-------------
 *
 * Exercise 15.20: Write code to test your answers to the previous two
 * exercises.
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

#include "TestClasses.h"


int main()
{
    Pub_Derv d1;
    Base *p = &d1;

    Priv_Derv d2;
    //p = &d2;    // Class 'Base' is a private base class of class 'Priv_Derv'

    Prot_Derv d3;
    //p = &d3;    // Class 'Base' is a protected base class of class 'Prot_Derv'

    Derived_from_Public dd1;
    p = &dd1;

    Derived_from_Private dd2;
    // Class 'Base' is a private base class of class 'Derived_from_Private'
    // p = &dd2;

    Derived_from_Protected dd3;
    // Class 'Base' is a protected base class of class 'Derived_from_Protected'
    // p = &dd3;

    return 0;
}