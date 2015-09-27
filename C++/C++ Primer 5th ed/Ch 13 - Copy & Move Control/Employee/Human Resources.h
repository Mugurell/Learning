//
// Created by Lingurar Petru-Mugurel on 06.07.2015.
//

#ifndef EMPLOYEE_EMPLOYPEOPLE_H
#define EMPLOYEE_EMPLOYPEOPLE_H

#include <vector>

#include "Employee.h"


// Will create nr number of Employee objects and return them in a vector
std::vector<Employee> employPeople(int nr);

void printEmployees(const std::vector<Employee> &employees);

#endif //EMPLOYEE_EMPLOYPEOPLE_H
