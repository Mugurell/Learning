//
// Created by Lingurar Petru-Mugurel on 21-Jul-15.
//

#include "PrintString.h"


std::string
PrintString::operator() ()const
{
    std::string line;
    std::getline(in, line);

    // will return a string representing a line of text read from an istream&
    // or an empty string if the read failed
    return in? line : std::string();
}