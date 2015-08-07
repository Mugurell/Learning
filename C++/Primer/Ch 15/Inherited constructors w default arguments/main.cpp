/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          04 Aug 2015, 21:47:23:913
 *  Last updated:     05 Aug 2015, 16:42:59:785  
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
 *  left-most, non-defaulted parameter in the base class.
 *  ...
 *  the default, copy, and move constructors are not inherited. These
 *  constructors are synthesized using the normal rules. An inherited
 *  constructor is not treated as a user-defined constructor.
 *  Therefore, a class that contains only inherited constructors will have a
 *  synthesized default constructor."
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  What I've gathered:
 *  - Default constructor synthesized by the compiler even though I have
 *   another defined constructor in the derived's body !
 *   This because an inherited constructor is not treated like a user defined
 *   constructor.
 *   It's form should be something like:
 *      Derived() : Base();
 *   In this little program, the first test ends up constructing a new Derived
 *   element by calling the base default constructor.
 *
 *  - Default arguments of the Base constructors are not inherited!!!
 *  BUT the way it works we'll get to the same end result.
 *   See http://stackoverflow.com/questions/31830780
 *   In our case, the rule "the derived class gets multiple inherited
 *   constructors inwhich each parameter with a default argument is
 *   successively omitted." will introduce this candidates:
 *     Derived(int a, char c, int a2, char c2) :
 *             Base(int a, char c, int a2, char c2) { }
 *     Derived(int a, char c, int a2)     :    Base(int a, char c, int a2) { }
 *     Derived(int a, char c)             :    Base(int a, char c) { }
 *     Derived(int a)                     :    Base(int a) { }
 *   The default arguments are not inherited - we just get a different
 *   constructor for each number of arguments.
 *   So our second and third tests will call
 *      Derived(int a)                  :   Base(int a)
 *      Derived(int a, char c, int a2)  :   Base(int a, char c, int a2)
 *   And both those Base contructors (inherited by Derived) will call
 *      Base(int x_, int y_ = 88, int z_ = 99).
 *   because Derived doesn't have default arguments, but Base still does.
 *   So the end result is the same - just how we get there is a bit different.
 *
 *  - Most interesting is the last test though..
 *   When looking through the error messages from the compiler it shows how
 *   it tried to call the default constructor - Derived::Derived(), then a
 *   constructor with fewer and fewer arguments (until 1)
 *   subtracting arguments from the right to left.
 *   This confirms that "the derived class gets multiple inherited
 *   constructors in which each parameter with a default argument is
 *   successively omitted".
 *
 *
********************************************************************************
*******************************************************************************/


#include <iostream>

#include "Classes.h"


int main()
{
    // Test the derived's default constructor
    Derived a;
    a.debug();

    // Test the derived's constructor which should take just one int
    // based on CPP Primer - the member for which the base constructor does not
    // define a default
    Derived b(33);
    b.debug();

    // Test the derived's constructor with 3 arguments.
    // Will also default initialize the forth with the value in the constructor
    Derived c(44, 'a', 44);
    c.debug();

    // Test the derived's constructor with 4 arguments.
    // corresponding to the parameters of the base inherited constructor
    Derived d(55, 'a', 55, 'b');
    d.debug();

    /*
     * This will enlighten on the multiple constructors inherited from base
     * ... from the only base constructor...
     * Expect not to compile. See the build error messages.
     */
     //Derived e(9, 'j', 9, 'a', 654.090f);
    return 0;
}