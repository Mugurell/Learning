//
// Created by mugurel on 24.05.2015.
//

#ifndef EX7_3_PERSON_H
#define EX7_3_PERSON_H

#include <iostream>
#include <string>

class Person {
public:
    Person() = default;
    Person(std::string n, std::string a): name(n), address(a) { }

    void fill();
    std::ostream& read(std::ostream&);
private:
    std::string name {"John Doe"};
    std::string address = "Doesia";

    friend std::ostream& read(Person);
    friend void fill(Person&);
};

std::ostream& read(Person);
void fill(Person&);

#endif
