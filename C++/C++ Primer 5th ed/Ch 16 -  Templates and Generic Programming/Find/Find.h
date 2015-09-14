/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          10-Aug-15, 01:25 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  ---
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  "Authors of templates should provide a header that contains the template
 *  definition along with declarations for all the names used in the class
 *  template or in the definitions of its members. Users of the template must
 *  include the header for the template and for any types used to instantiate
 *  that template."
 *  "Template programs should try to minimize the number of requirements
 *  placed on the argument types."
 *  Make sure the only place that includes <X>.tpp is the last line in <X>.h
 *
********************************************************************************
*******************************************************************************/



#ifndef FIND_FIND_H
#define FIND_FIND_H


template<typename InputIterator, typename Searched>
InputIterator Find(InputIterator begin, InputIterator end,
                   const Searched &item);


#include "Find.tpp"

#endif //FIND_FIND_H