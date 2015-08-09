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
 *  The class should have a default constructor and a constructor that takes
 *  a string representing the employee’s name.
 *  Each constructor should generate a unique ID by incrementing a static data
 *  member.
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


#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H


#include <iostream>
#include <string>


class Employee {
public:
    Employee();
    Employee(const std::string& name_);

    std::string getName() const;
    int getIDNo() const;


private:
    std::string name;
    int IDNo;
    static int uniqueID;

};
#endif //EMPLOYEE_EMPLOYEE_H
