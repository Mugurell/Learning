/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 6 iulie 2015, 10:53:02 +0300
**  Last updated:     miercuri 8 iulie 2015, 16:58:05 +0300
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
**              int i;
**            };
**  Exercise 13.8: Write the assignment operator for the HasPtr class from
**  exercise 13.5. As with the copy constructor, your assignment operator 
**  should copy the object to which ps points.
**  Exercise 13.11: Add a destructor to your HasPtr class from the previous
**  exercises.
**  Exercise 13.22: Assume that we want HasPtr to behave like a value. That
**  is, each object should have its own copy of the string to which the objects
**  point. We’ll show the definitions of the copy-control members in the next
**  section. However, you already know everything you need to know to
**  implement these members. Write the HasPtr copy constructor and copy-
**  assignment operator before reading on.
**  Exercise 13.30: Write and test a swap function for your valuelike version 
**  of HasPtr. Give your swap a print statement that notes when it is executed.
**  Exercise 13.31: Give your class a < operator and define a vector of
**  HasPtrs. Give that vector some elements and then sort the vector.
**  Note when swap is called.
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
**  Made a little modification, the int member can also be constructed with a
**  value passed by the user. 
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <new>
#include <utility>      // for std::swap. C++98 contains it in <algorithm>



class HasPtr {
    friend void swap(HasPtr &lhc, HasPtr &rhc);
public:
    HasPtr(const std::string &s = "", const int &i_ = 0)
        : ps(new std::string(s)), i(i_) { 
        std::cout << "*Constructed Hasptr: " << *ps << ' ' << i << std::endl; }

// copy constructor (rule of 3/5)
    HasPtr(const HasPtr &received_)
        : ps(new std::string(*received_.ps)), i(received_.i) {
        std::cout << "*Copied " << *ps << ' ' << i << std::endl; }

// copy assignment operator (rule of 3/5)
//    HasPtr& operator=(const HasPtr &newObject_);
    HasPtr& operator=(HasPtr copyFromMe);

// this will be used as strict weak ordering in various algorithms
    bool operator<(const HasPtr &rightOperand) const;

// destructor needed because ps points to heap allocated memory
    ~HasPtr() { delete /*this->*/ ps; std::cout << "**Destructor called\n"; }

// function used to print the whole content of the object of class's type
    void print() const;

private:
    std::string *ps;
    int i;
};






/*****************************************************************************
** The function described below is deprecated because since we're defined our
** own swap function, a better copy-assignment operator is possible
*/////////////////////////////////////////////////////////////////////////////
// When an operator is a member function, the left-hand operand is bound to
// the implicit this parameter and the right-hand operand in a binary operator,
// such as assignment, is passed as an explicit parameter.
// Best practice is for the assignement operator to return a reference to
// it's left-hand operand!
// Here we initialize new_ps to point to a string allocated on heap but which
// is a copy of the string contained in the received parameter. Hence, when the
// function ends and delete will be called on new_ps, it will not also delete
// the string contained by the argument, which may still be used in the caller.

// HasPtr& HasPtr::operator=(const HasPtr &newObject_ ) {
//     std::string *new_ps = new std::string(*newObject_.ps);
//     delete /*this->*/ ps;       // free the old memory
//     /*this->*/ ps = new_ps;     // now point to new
//     /*this->*/ i = newObject_.i;
//     return *this;
// }
/////////////////////////////////////////////////////////////////////////////



/*
** The function below uses the our defined swap function
*/
// This new implementation automatically handles self assignment and is 
// automatically exception safe. By copying the right-hand operand
// before changing the left-hand operand, it handles self assignment in the 
// same was as we did in our original assignment operator.
// It manages exceptionsafety in the same way as the original definition as 
// well. The only code that might throw is the new expression inside the copy
// constructor. If an exception occurs, it will happen before we have 
// changed the left-hand operand.

// Note that copyFromMe is passed by value, which means the HasPtr copy
// constructor copies the string and the int in the right-hand operand
// into copyFromMe.
inline HasPtr&
HasPtr::operator=(HasPtr copyFromMe) {
    // swaps the content of the left-hand operand with 
    // the local variable  copyFromMe
    swap(*this, copyFromMe);    // copyFromMe points to the memory this* used 
    std::cout << "\n**copy-assignment operator called**\n";
    return *this;               // copyFromMe is destroyed which deletes
                                // the pointer to string of it
}




// This functions will be used as a Strict Weak Ordering - a binary predicate
// that compares two objects, returning true if the first precedes the second. 
// Will follow the mathematical definition of a strict weak ordering,
inline bool
HasPtr::operator<(const HasPtr &rightOperand) const {
    // if the first element in the leftOperand has a value less than
    // the first element in the RightOperand.
    if (*ps < *rightOperand.ps) {
        return true;
    }
    // if the first element in leftOperand is equivalent to the first element
    // in rightOperand test if the second element has a lesser value.
    else if(!(*ps > *rightOperand.ps)
            && (i < rightOperand.i)) {
        return true;
    } 
    // if the above checks failed means that we have at least 
    // equivalent operands and so the left one is not lesser than the right.
    else 
        return false;
}




// swap is usually called when different algorithms want to reorder the
// elements of the class.
// Defining our own swap is an important optimization for classes that allocate
// resources in that it will avoid some unnecessary copies of the objects 
// allocated on the freestore
inline void
swap(HasPtr &lhc, HasPtr &rhc) {
    using std::swap;
    swap(lhc.ps, rhc.ps);
    swap(lhc.i, rhc.i);

    std::cout << "\n**swap(left class, right class)**\n";
}




// the print function is useful in knowing if the class was successfully
// created and what elements does it contain
inline void
HasPtr::print() const {
    std::cout << "\tstring: " << *ps << ", int: " << i << std::endl;
}