/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          31-Jul-15, 06:56 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Exercise 15.18: Given the classes from page 612 and page 613, and assuming
 *  each object has the type specified in the comments, determine which of these
 *  assignments are legal. Explain why those that are illegal aren't allowed.
 *      Base *p = &d1;  // d1 has type Pub_Derv
 *      p = &d2;        // d2 has type Priv_Derv
 *      p = &d3;        // d3 has type Prot_Derv
 *      p = &dd1;       // dd1 has type Derived_from_Public
 *      p = &dd2;       // dd2 has type Derived_from_Private
 *      p = &dd3;       // dd3 has type Derived_from_Protected
 *
 * Exercise 15.19: Assume that each of the classes from page 612 and page
 * 613 has a member function of the form:
 *          void memfcn(Base &b) { b = *this; }
 * For each class, determine whether this function would be legal.
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



#ifndef CONVERSION_TESTS_HEADER_FILE_H
#define CONVERSION_TESTS_HEADER_FILE_H


class Base {
public:
    void pub_mem();     // public member

protected:
    int prot_mem;       // protected member

private:
    char priv_mem;      // private member
};


struct Pub_Derv : public Base {
    // Implicit conversion from derived to base in the body of memfcn.
    void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base {
    void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
    void memfcn(Base &b) { b = *this; }
};


struct Derived_from_Public : public Pub_Derv {
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : public Prot_Derv {
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv {
    // void memfcn(Base &b) { b = *this; }
    // You can't really inherit anything from a private class, do you?
};


#endif //CONVERSION_TESTS_HEADER_FILE_H
