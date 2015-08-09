//
// Created by Lingurar Petru-Mugurel on 06.07.2015.
//

#include <string>
#include <algorithm>

#include "Human Resources.h"

std::vector<Employee>
employPeople(int nr) {
    std::vector<Employee> newlyEmployed;
    std::cout << "\n***Remember: Type IDK if you don't know atm the employess"
              << " name***\n";
    while (nr-- > 0) {
        std::cout << "\nNew employee name: ";
        std::string name;
        std::cin >> name;
        if (name == "IDK") {
            Employee johnDoe;
            newlyEmployed.emplace_back(johnDoe);
        }
        else {
            Employee newEmployee{name};
            newlyEmployed.emplace_back(newEmployee);
        }
    }

    return newlyEmployed;
}


void printEmployees(const std::vector<Employee> &employees) {
    std::for_each(employees.cbegin(), employees.cend(),
                  [](const Employee& a) { std::cout << "Employee ID: "
                                                    << a.getIDNo()
                                                    << " - " << a.getName()
                                                    << std::endl; });
}
