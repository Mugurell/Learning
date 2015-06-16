//
// Created by Lingurar Petru-Mugurel on 06.06.2015.
//

#include "Person.h"
#include <cstring>



Person::Person() {
    Lname = NULL;
    Fname = NULL;
    age = 20;
}
Person::Person(const char *ln, const char *fn, unsigned nr) {
    int len = strlen(fn) + 1;
    Lname = new char[len];
    strcpy(Lname, ln);

    len = strlen(fn) + 1;
    Fname = new char[len];
    strcpy(Fname, fn);

    age = nr;
}


// Doesn't return nothing, doesn't have any parameters.
Person::~Person() {
    // after delete, the brackets are needed to symbol an c style array;
    delete [] Lname;
    delete [] Fname;
    std::cout << "\n***Person distructed!***\n";
}

/*
int return_oldest_pers(const Person &received) const {
    if (*this == recived) {
        std::cerr << "\nError: Can't compare same person!\n";
        return 0;
    } else {
        return (this->age > received.age
                ? 1 : *this.age == received.age
                        ? 0 : -1);
    }
}
*/


int
Person::operator<(const Person &received)
{
    if (this == &received) {
        std::cerr << "\nError: Can't compare same person!\n";
        return 0;
    } else {
        return (this->age > received.age
                ? 1 : this->age == received.age
                        ? 0 : -1);
    }
}


std::ostream& operator<<(std::ostream &os, const Person &pers)
{
    os << pers.Lname << ' ' << pers.Fname << ": " << pers.age;
    return os;
}


