/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 6 iulie 2015, 15:23:18 +0300
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
**  Exercise 13.13: A good way to understand copy-control members and
**  constructors is to define a simple class with these members in which each
**  member prints its name:
**      struct X {
**          X() {std::cout << "X()" << std::endl;}
**          X(const X&) {std::cout << "X(const X&)" << std::endl;}
**      };
**
**  Add the copy-assignment operator and destructor to X and write a program 
**  using X objects in various ways: Pass them as nonreference and reference 
**  parameters; dynamically allocate them; put them n containers; and so forth.
**  Study the output until you are certain you understand when and why each 
**  copy-control member is used. As you read the output, remember that the 
**  compiler can omit calls to the copy constructor.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  ---
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <memory>


struct X {
    //  simple constructor
    X() { std::cout << "\tConstruct X()" << std::endl; }

    // constructor which takes another element of this type
    X(const X &newObject_) : nr(newObject_.nr)
        { std::cout << "\tConstruct X(const X&)" << std::endl; }

    // constructor which takes an int to initialize it's int member
    X(const int &newValue_) : nr(newValue_)
        { std::cout << "\tConstruct X(const int&)" << std::endl; }

    // copy assignment operator
    X& operator=(const X &newObject_) 
        { nr = newObject_.nr; 
        std::cout << "\tnr = newObject_.nr" << std::endl;
        return *this; }

    // destructor
    ~X() { std::cout << "\tDestructed X" << std::endl; }

    int nr;
};


void getFreakyWithIt(const X &received);
void deleter(X*);

int main()
{
    std::cout << "\nSo we have a structure with a zdranf object (one) "
              << "\nwhich has 23 zghiti:\n";
    X one(23);
    std::cout << "one - " << one.nr
              << "\n\nIf we're copy it's value into a new object, we'd have:\n";
    X two(one);
    std::cout << "two - " << two.nr
              << "\n\nLet's send it to a function as a reference "
              << "and play with it some more there..\n"
              << "---------------------------------------\n";
    getFreakyWithIt(two);
    std::cout << "----------------------------------------\n"
              << "And we're back to main";

    std::cout << "\n\nPretty cool, huh?\n" << std::endl;
    return 0;
}


void
getFreakyWithIt(const X &received) {
    X three(received);
    std::cout << "\nSo we have :\nf_one - " << three.nr;
    std::cout << "\n\nWill now create a  vector of elements of the "
              << "structures type:\n";
    std::vector<X> viX;
    std::cout << "\nWill reserve only 5 places in it..(vec.reserve(5))\n";
    viX.reserve(5);
    std::cout << "\npush_back in it\n";;
    viX.push_back(three);
    std::cout << "and then shrink_to_fit\n";
    viX.shrink_to_fit();

    std::cout << "\nNow will create a shared_ptr to a dinamically allocated"
              << " object, constructed from another new object:\n";
    X ff(55);
    std::shared_ptr<X> ptr = std::make_shared<X>(ff);
    std::cout << "Shared_ptr five - " << ptr->nr
              << "\nAnd now will end this function\n";
}


void deleter(X*) { 
    std::cout << "Custom deleter called for the shared_ptr\n";
}