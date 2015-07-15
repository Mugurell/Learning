/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 6 iulie 2015, 10:53:02 +0300
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
**  Exercise 13.5: Given the following sketch of a class, write a copy con-
**  structor that copies all the members. Your constructor should dynamically
**  allocate a new string (§ 12.1.2, p. 458) and copy the object to which ps
**  points, rather than copying ps itself.
**            class HasPtr {
**            public:
**              HasPtr(const std::string &s = std::string())
**                  : ps(new std::string(s)), i(0) { }
**            private:
**              std::string *ps;
**         
**            };
**  Exercise 13.8: Write the assignment operator for the HasPtr class from
**  exercise 13.5. As with the copy constructor, your assignment operator 
**  should copy the object to which ps points.
**  Exercise 13.11: Add a destructor to your HasPtr class from the previous
**  exercises.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---  
**
**  Notes:
**  Usually declarations stays in headers and definitions in implementation
**  files (.cpp).
**  Inline is used normally when we want to indicate that some functions are to
**  be defined in the header.
**  When we declare and define some functions in the header, the declaration
**  should be repeated in the implementation file in which there are other
**  methods defined.
**  Following the rule of three/five, if we need a destructor (needed because
**  the synthesized destructor will not delete out *ps which points to a
**  dinamically allocated object) we usuallly also need copy constructor and
**  copy assignment operator. The other ule of thumb is that if a class needs
**  a constructor it almost surely needs a copy constructor as well. But if a
**  class needs a copy constructor/assignment operator it does not(necessarily)
**  indicate the need for a destructor.
**  See - http://stackoverflow.com/questions/4782757/
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <new>


class HasPtr {
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0) { }

// copy constructor (rule of 3/5)
    HasPtr(const HasPtr &received_)
        : ps(new std::string(*received_.ps)), i(received_.i) { }

// copy assignment operator (rule of 3/5)
    HasPtr& operator=(const HasPtr &received_);

// destructor needed because ps points to heap allocated memory
    ~HasPtr() { delete /*this->*/ ps; }

private:
    std::string *ps;
    int i;
};


// When an operator is a member function, the left-hand operand is bound to
// the implicit this parameter and the right-hand operand in a binary operator,
// such as assignment, is passed as an explicit parameter.
// Best practice is for the assignement operator to return a reference to
// it's left-hand operand!
// Here we initialize new_ps to point to a string allocated on heap but which
// is a copy of the string contained in the received parameter. Hence, when the
// function ends and delete will be called on new_ps, it will not also delete
// the string contained by the argument, which may still be used in the caller.
inline HasPtr&
HasPtr::operator=(const HasPtr &newObject_) {
    std::string *new_ps = new std::string(*newObject_.ps);
    delete /*this->*/ ps;
    /*this->*/ ps = new_ps;
    /*this->*/ i = newObject_.i;
    return *this;
}