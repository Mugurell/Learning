/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          06 Jul 2015, 22:40
 *  Last updated:           ---
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
 *  Implementation file for the Employee class.
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
*******************************************************************************
******************************************************************************/



#include "Employee.h"


int Employee::uniqueID = 321;

Employee::Employee() : name("John Doe"), IDNo(uniqueID++) { }
Employee::Employee(const std::string &name_) : name(name_), IDNo(uniqueID++){ }

std::string Employee::getName() const {
    return this->name;
}

int Employee::getIDNo() const {
    return this->IDNo;
}
