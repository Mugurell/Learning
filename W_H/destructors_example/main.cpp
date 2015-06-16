/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          06.06.2015 13:04
 *  Last updated:     08 Jun 2015, 16:01  
 *
 *  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic 
 *	 (g++ 5.1)		    
 *
 *  Execution:    ./...
 *
 *  Description:
 *  --- This is a description of what the program does ---
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Expected result:
 *  --- You can write here the execution command & the expected result --- 
 *
 *  Notes:
 *  --- Anything that stands out ---
 *  --- Or needs to be treated with special attention ---
 *
*******************************************************************************
******************************************************************************/


#include <iostream>
#include "Person.h"
#include <vector>
#include <algorithm>


int main()
{
    {
        std::cout << "\nlet's play around with some persons\n\n" << std::endl;

        Person gangbang[] = {
            Person ("Goran", "Horia-Mihail", 30),
            Person ("Bella", "Ana", 17),
            Person ("Vasile", "Grigore", 43)
        };
/* This calls the default copy constructor, which does nothing, or at best
 * member-by-member initialization
 *
        Person mihai = horia;
 */


/* This calls the default assignment operation.
 * It will surely do member-by-member initialization!,
 * Which is wrong in this case because it will make a shallow copy, and not
 * deep copying (it will share the pointee - vali.Fname will point to the same
 * memory location to which horia.Fname points. It will not copy the values,
 * from one class object to another).
 * This leads to the bad result that when horia is destroyed, the members of
 * vali, which pointed to the same (now destryoed) memory location leads to
 * undefined behaviour!!!!!
 *
 *      Person vali;
        vali = horia;
 */


//        std::sort(gangbang, std::end(gangbang));
//
//        for (Person pers : gangbang) {
//            std::cout << pers;
//        }

        for (int x = 0; x < 3; x++) {
            std::cout << gangbang[x] << '\n';
        }
    }

    return 0;
}
