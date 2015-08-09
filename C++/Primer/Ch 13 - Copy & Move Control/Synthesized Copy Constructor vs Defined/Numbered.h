//
// Created by Lingurar Petru-Mugurel on 06.07.2015.
//


#ifndef UNTITLED_NUMBERED_H
#define UNTITLED_NUMBERED_H


#include <iostream>


class Numbered {
public:
    // default constructor
    Numbered();

#ifdef ex_fifteen
// Assume the class has a copy constructor that generates a new serial number.
// Otherwise the synthesized copy constructor/assignment operator will be used.
    // copy constructor
    Numbered(const Numbered &copyFromMe_);

    // copy assignment operator
    Numbered& operator=(const Numbered &copyFromMe_);
#endif //ex_fifteen

    // static data members are associated with the class,
    // rather than with individual objects of the class type
    static int serialNoCount;
    int serialNo;
};



#endif //UNTITLED_NUMBERED_H
