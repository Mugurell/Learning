/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 23 iunie 2015, 18:26:55 +0300
**  Last updated:     mari 7 iulie 2015, 21:24:09 +030
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
**  Exercise 12.2: Write your own version of the StrBlob class including the
**  const versions of front and back.
**  Exercise 13.25: Assume we want to define a version of StrBlob that acts
**  like a value. Also assume that we want to continue to use a shared_ptr so
**  that our StrBlobPtr class can still use a weak_ptr to the vector. Your
**  revised class will need a copy constructor and copy-assignment operator but
**  will not need a destructor. Explain what the copy constructor and copy-
**  assignment operators must do. Explain why the class does not need a
**  destructor.
**  Exercise 13.26: Write your own version of the StrBlob class described in
**  the previous exercise.
**  Exercise 14.18: Define relational operators for your StrBlob,
**  StrBlobPtr, StrVec, and String classes.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---
**
**  Notes:
**  We use the arrow operator to use various vector functions because
**  data_ is a shared_ptr - so it first must be dereferenced.
**
**  Keep in mind that when we call const member function, this means that
**  the data_ member will be a const shared_ptr and as such must point to the
**  same vector. We cannot change the address to which it points.
**  But the underlying vector can be changed.
**  As such we could have push_back() and pop_back() with a const *this.
**  But this break the accepted convention that const member functions should
**  not change the observable state (size(), empty()) of the objects !!!!
**
*******************************************************************************
******************************************************************************/


#ifndef STRBLOBPTR_STRBLOB_H
#define STRBLOBPTR_STRBLOB_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>          // shared_ptr, make_shared()
#include <stdexcept>       // out_of_range



/*
** Forward declaration needed for friend declaration in StrBlob
*/
class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;

    friend bool operator< (const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator> (const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    // Copy constructor - ex 13.26
    StrBlob(const StrBlob &received);

    // Copy assignment operator - ex 13.26
    StrBlob& operator=(const StrBlob &received);

    size_type size() const;
    bool empty() const;
    void push_back(const std::string &t);
    void pop_back();

    StrBlobPtr begin();
    StrBlobPtr end();
// element access
    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;
private:
    std::shared_ptr<std::vector<std::string>> data_;

// throws msg if data_[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};


#endif //STRBLOBPTR_STRBLOB_H