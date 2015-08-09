/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          06 Jul 2015, 22:32
 *  Last updated:     07 Jul 2015, 11:17
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
 *  Exercise 13.18: Define an Employee class that contains an employee name
 *  and a unique employee identifier. Give the class a default constructor and a
 *  constructor that takes a string representing the employee’s name.
 *  Each constructor should generate a unique ID by incrementing a static data
 *  member.
 *  Exercise 13.19: Does your Employee class need to define its own versions
 *  of the copy-control members? If so, why? If not, why not? Implement
 *  whatever copy-control members you think Employee needs.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  For now I don't need any copy-control members.
 *  Defined some helping functions in "Human Resources.h"
 *
*******************************************************************************
******************************************************************************/



#include <iostream>
#include <sstream>

#include "Employee.h"
#include "Human Resources.h"


int main()
{
    std::cout << "\nLet's say we have a small bussiness with 4 employess.";
    std::vector<Employee> Employees = employPeople(3);

    std::cout << "\nCool, so we have:\n";
    printEmployees(Employees);


    return 0;
}
