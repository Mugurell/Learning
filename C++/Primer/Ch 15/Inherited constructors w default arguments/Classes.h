/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          04-Aug-15, 09:34 PM
 *  Last updated:     05 Aug 2015, 16:43:04:435 
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Test how the following excerpt from CPP Primer pg 629 applies:
 *  "If a base-class constructor has default arguments (§6.5.1, p. 236), those
 *  arguments are not inherited. Instead, the derived class gets multiple
 *  inherited constructors in which each parameter with a default argument is
 *  successively omitted. For example, if the base has a constructor with two
 *  parameters, the second of which has a default, the derived class will
 *  obtain two constructors: one with both parameters (and no default argument)
 *  and a second constructor with a single parameter corresponding to the
 *  left-most, non-defaulted parameter in the base class."
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



#ifndef INHERITED_CONSTRUCTORS_W_DEFAULT_ARGUMENTS_CLASSES_H
#define INHERITED_CONSTRUCTORS_W_DEFAULT_ARGUMENTS_CLASSES_H


#include <iostream>


class Base {
protected:
    int a;
    char c;
    int a2;
    char c2;

public:
    Base() = default;

    Base(int a_, char c_ = 'Z', int a2_ = 10, char c2_ = 'Z')
            : a(a_), c(c_), a2(a2_), c2(c2_) { }

    virtual void debug() const
    {
        std::cout << "\nint1 - " << a << ", char1 - " << c
                  << ", int2 - " << a2 << ", char2 - " << c2 << '\n';
    }
};


struct Derived : Base {
private:
    float f = 0.4535;

public:
    /* A default constructor will implicitly be synthesized by the compiler
     * because technically I didn't define any other constructors
     */
    // Derived() : Base() { }

    using Base::Base;
    /* The call above will introduce:
     *     Derived(int a, char c, int a2, char c2) :
     *             Base(int a, char c, int a2, char c2) { }
     *     Derived(int a, char c, int a2)    :    Base(int a, char c, int a2) {}
     *     Derived(int a, char c)            :    Base(int a, char c) { }
     *     Derived(int a)                    :    Base(int a) { }
     *
     *  And all of that Base constructors will call
     *      Base(int x_, int y_ = 88, int z_ = 99)
     */

    virtual void debug() const override
    {
        std::cout << "\nint1 - " << a << ", char1 - " << c
                  << ", int2 - " << a2 << ", char2 - " << c2
                  << ", float - " << f << '\n';
    }
};



#endif //INHERITED_CONSTRUCTORS_W_DEFAULT_ARGUMENTS_CLASSES_H
