//
// Created by Lingurar Petru-Mugurel on 06.07.2015.
//

#include "PrintFunction.h"


#ifdef const_f_parameter
// if the user wants to use a print function for which the argument is const

void f(const Numbered &item) { std::cout << item.serialNo << std::endl; }

#endif


void f(Numbered &item) { std::cout << item.serialNo << std::endl; }