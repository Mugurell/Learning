//
// Created by mugurel on 24.05.2015.
//

#include <iostream>
#include "Person.cc"

int main() {
    std::cout << "So let's say we have a person:\n\t";
    Person a("Gogu", "Baicoi");
    read(a) << ".\n" << std::endl;

    std::cout << "Who later will fall in love with: [name]_[address]\n\t";
    Person b;
    b.fill();

    std::cout << "And after some time they'll have a kid named: [name]_[address]"
                         "\n\t";
    Person c;
    fill(c);

    std::cout << "\nSo later in time, there will be a beautifully familly "
                         "composed of\n\t";
    a.read(std::cout) << "\n\t";
    read(b) << "\n\t";
    read(c) << "\n" << std::endl;

    return 0;
}