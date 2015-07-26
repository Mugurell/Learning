//
// Created by Lingurar Petru-Mugurel on 21-Jul-15.
//

#ifndef PRINTSTRINGFUNCTOR_PRINTSTRING_H
#define PRINTSTRINGFUNCTOR_PRINTSTRING_H


#include <iostream>
#include <string>
#include <vector>


class PrintString {
public:
    PrintString(std::istream &i = std::cin) : in(i) { }
    std::string operator() () const;

private:
    std::istream& in;
};



#endif //PRINTSTRINGFUNCTOR_PRINTSTRING_H
