/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 8 iulie 2015, 13:08:16 +0300
**  Last updated:           ---
**
**  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Copy constructor. De ce nu da delete la pointerul existent inainte de a ii
**  assigna un alt pointee ???
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---  
**
**  Notes:
**  copy CONSTRUCTOR
**  E folosit ca sa construiesti un element nou, dandu-i argument in paranteza 
**  un element existent...
**  Eu credeam ca il folosesc tot ca pe assignement, daca vreau sa schimb 
**  valorile intr-o clasa construita deja, in loc sa dau clasa1 = clasa 2, 
**  ziceam eu ca pot sa dau clasa1(clasa2).
**  Asadar daca atunci construiesc obiectul folosind copy constructor, normal 
**  ca nu tre' sa dau delete la ce avea pointerul inainte pt ca pointerul ala 
**  nu exista inainte.
**  http://www.vedetetv.ro/_pics/articles/hyu2sgzoxo.jpg
**
*******************************************************************************
******************************************************************************/



#include "understanding_the_copy_constructor.h"


int main()
{
    std::cout << "\nLet's say we have a 2 ints -\n";
    Test unu, doi(5);
    std::cout << '\t' << unu.getNr() << ' ' << doi.getNr() << '\n'; 
    std::cout << "Now if were to use the copy constructor to create a new one"
              << "\nwith the same value as the second int,"
              << "\nand then we'd assign the third to the first we'd have :\n";
    Test trei(doi);
    unu = trei;
    std::cout << '\t' << unu.getNr() << ' ' << doi.getNr() 
              << ' ' << trei.getNr() << '\n';
    
    return 0;
}