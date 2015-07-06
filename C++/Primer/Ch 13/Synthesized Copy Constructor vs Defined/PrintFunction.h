//
// Created by Lingurar Petru-Mugurel on 06.07.2015.
//

#ifndef SYNTHESIZED_COPY_CONSTRUCTOR_VS_DEFINED_PRINTFUNCTION_H
#define SYNTHESIZED_COPY_CONSTRUCTOR_VS_DEFINED_PRINTFUNCTION_H


#include "Numbered.h"


#ifdef const_f_parameter
// if the user wants to use a print function for which the argument is const
void f(const Numbered &item);

#else
void f(Numbered &item);

#endif

#endif //SYNTHESIZED_COPY_CONSTRUCTOR_VS_DEFINED_PRINTFUNCTION_H
