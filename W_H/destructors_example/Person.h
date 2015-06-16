//
// Created by Lingurar Petru-Mugurel on 06.06.2015.
//

#ifndef CLASSES_DESTRUCTORS_W_H_PERSON_H
#define CLASSES_DESTRUCTORS_W_H_PERSON_H

#include <iostream>


class Person {
private:
    char *Lname;
    char *Fname;
    unsigned age;

public:
    Person();
    Person(const char *ln, const char *fn, unsigned nr = 25);

    // now let's declare a destructor. Only one permitted!
    // Doesn't return nothing, doesn't have any parameters.
    ~Person();
    ///int return_oldest_pers(const Person &) const;

    // overloaded la <
    int operator<(const Person&);
    // friend because when overloading operators, the function
    // can only have just one parameter.
    friend std::ostream& operator<<(std::ostream&, const Person&);
};




#endif //CLASSES_DESTRUCTORS_W_H_PERSON_H
