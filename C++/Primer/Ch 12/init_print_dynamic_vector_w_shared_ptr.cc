/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 24 iunie 2015, 23:09:20 +0300
**  Last updated:           ---
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Exercise 12.7: Redo the previous exercise, this time using shared_ptr.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**
**  Notes:
**  Cand utilizezi un shared_ptr nu mai trebuie sa urmaresti sa dai delete().
**  Atunci cand cade de pe stack sau count-ul ii ajunge la 0 o sa distruga
**  automat obiectul catre care pointa si o sa ii elibereze memoria ocupata.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <memory>


// Will return a shared_ptr to a vector of ints.
std::shared_ptr<std::vector<int>> CreateDinamicVector();


// Takes a pointer to a vector of ints and initialize it from std::cin.
void InitDinamicVector(std::shared_ptr<std::vector<int>>);

// Will print the elements of the pointee.
void PrintDinamicVector(std::shared_ptr<std::vector<int>>);


int main()
{
    std::shared_ptr<std::vector<int>> dinamic_vector = CreateDinamicVector();
    std::cout << "\nQuick, help me initializing a dynamically allocated"
              << " vector of ints:"
              << std::endl;
    InitDinamicVector(dinamic_vector);

    std::cout << "\n\nCurious about what I've stored?" 
              << "\nOn pointer to " << dinamic_vector << " I have.. "
              << std::endl;
    PrintDinamicVector(dinamic_vector);

    std::cout << "\n\nLet's check now if the dynamic vector was successfully"
              << " freed:"
              << "\n\n\tThe vector still points to " << dinamic_vector
              << "\n\nLet's try to print the values of it's pointee:\n";
    PrintDinamicVector(dinamic_vector);
    
    std::cout << "\n\nPretty cool, huh?\n" << std::endl;

    return 0;
}


std::shared_ptr<std::vector<int>>
CreateDinamicVector() {
    return std::make_shared<std::vector<int>> ();
}


// Initialize the dinamic object, received as pointer by reading from std::cin
// until there is no valid input.
void
InitDinamicVector(std::shared_ptr<std::vector<int>> dinamic_vector) {
    int new_int_read;
    while (std::cin && std::cin >> new_int_read)
        dinamic_vector->push_back(new_int_read);
}


// Check if the vector received as a pointer has any elements and act 
// accordingly.
// As this is the last use of the vector to the dynamically alocated vector
// will also delete() it.
void
PrintDinamicVector(std::shared_ptr<std::vector<int>> dinamic_vector) {
    if (dinamic_vector != nullptr && dinamic_vector->size() > 0)
        for (const int &nr : *dinamic_vector)
            std::cout << nr << ' ';
    else
        std::cout << "\n\tThe received vector to print is empty!\n";
}