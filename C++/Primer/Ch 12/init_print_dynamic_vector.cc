/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 24 iunie 2015, 19:35:36 +0300
**  Last updated:     miercuri 24 iunie 2015, 22:50:23 +0300
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
**  Exercise 12.6: Write a function that returns a dynamically allocated vector
**  of ints. Pass that vector to another function that reads the standard input
**  to give values to the elements. Pass the vector to another function to print
**  the values that were read. Remember to delete the vector at the
**  appropriate time.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**
**  Notes:
**  I pass a reference to a pointer to the print function because I want to
**  destroy/free the memory of the pointee and also assign nullptr to the
**  received pointer. If I would send a simple pointer, I would pass it by
**  value - a copy of it's value -> any modification will only affect the local
**  copy of the pointer and not the caller !
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <new>      // for new and delete

// Will create a dynamically allocated vector of ints & return a pointer to it.
// It's the user's responsability to delete() the dynamic object, either by
// calling the PrintDinamicVector function which does this, either explicitly
std::vector<int>* CreateDinamicVector();


// Takes a pointer to a vector of ints and initialize it from std::cin.
void InitDinamicVector(std::vector<int>*);

// Will print the elements of the pointee.
// Because the received vector should be a vector to a dynamically allocated
// vector, and because this is the last use for it, it will delete() it.
void PrintDinamicVector(std::vector<int>*&);


int main()
{
    std::vector<int>* dinamic_vector = CreateDinamicVector();
    std::cout << "\nQuick, help me initializing a dynamically allocated"
              << " vector of ints:"
              << std::endl;
    InitDinamicVector(dinamic_vector);
    std::cout << "\n**Poiterul pointeaza catre " << dinamic_vector
              << "***" << std::endl;

    std::cout << "\n\nCurious about what I've stored?" << std::endl;
    PrintDinamicVector(dinamic_vector);

    std::cout << "\n\nLet's check now if the dynamic vector was successfully"
              << " freed:"
              << "\n\n\tThe vector now points to " << dinamic_vector
              << "\n\nLet's try to print the values of it's pointee:\n";
    PrintDinamicVector(dinamic_vector);
    
    std::cout << "\n\nPretty cool, huh?";

    return 0;
}


std::vector<int>*
CreateDinamicVector() {
    return new std::vector<int>;
}


// Initialize the dinamic object, received as pointer by reading from std::cin
// until there is no valid input.
void
InitDinamicVector(std::vector<int> *dinamic_vector) {
    int new_int_read;
    while (std::cin && std::cin >> new_int_read)
        dinamic_vector->push_back(new_int_read);
}


// Check if the vector received as a pointer has any elements and act 
// accordingly.
// As this is the last use of the vector to the dynamically alocated vector
// will also delete() it and assign nullptr to signal that is not used anymore.
void
PrintDinamicVector(std::vector<int> *&dinamic_vector) {
    if (dinamic_vector != nullptr && dinamic_vector->size() > 0)
        for (const int &nr : *dinamic_vector)
            std::cout << nr << ' ';
    else
        std::cout << "\n\tThe received vector to print is empty!\n";

    std::vector<int> ghita(10, 1);

// Don't forget to delete() the vector.
    delete dinamic_vector;
    dinamic_vector = nullptr;
}