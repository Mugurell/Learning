//
//  Author:           Lingurar Petru-Mugurel
//  Written:          05 Sep 2015  20:54:10
//  Last updated:           ---
//
//
//  Description:
//    OOP fun
//
//  Bugs:
//    --- None ---
//
//  TODO:
//    --- None --- 
//
//  Notes:
//    Cog is a strange breed inherited from both Dog and Cat, which are both Mammals.
//  To solve the dreaded diamond problem, the Dog and Cat classes used virtual inheritance.
//


#include "stdafx.h"

#include "Cat.h"
#include "Dog.h"
#include "Human.h"
#include "Mammals.h"
#include "Cog.h"


int main()
{
    // Mammals mammal;      // cannot instantiate abstract class

/*    Human human("John", 70, 2, 33.6, false);
    Dog dog("Ilie", 12, 4, 20.4);

    std::cout << '\n' << human << "\nwhile " << dog << "\n\n";*/

    // Cog was inherited from both Cat and Dog
    Cog cog("Cog", 1, 7, 324.99);   // will call it's own destructor
                                    // the dctor of the Cat and Dog (notice the reverse order)
                                    // the dctor of Mammals
                                    // (reverse order of how it was constructedd)



/*

    human.print_organs();   // calls the static Mammals::print_organs()
    human.breath();         // breathe using Mammal base class functionality
    human.talk();
    human.walk();
    human.attack();

    Cat cat;
    cat.breath();
    cat.talk();
    cat.walk();

    Dog dog;
    dog.breath();
    dog.talk();
    dog.walk();
*/

}