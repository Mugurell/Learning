/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 23 iunie 2015, 18:26:55 +0300
**  Last updated:     joi  17 iulie 2015, 17:53:09 +0300
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
**  Exercise 13.55: Add an rvalue reference version of push_back 
**  to your StrBlob.
**  Exercise 14.16: Define equality and inequality operators for your StrBlob,
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
**  the data_ member will be a const shared_ptr and as shuch must point to the
**  same vector. We cannot change the address to which it points.
**  But the underlying vector can be changed. 
**  As such we could have push_back() and pop_back() with a const *this.
**  But this break the accepted convention that const member functions should
**  not change the observable state (size(), empty()) of the objects !!!!
**
*******************************************************************************
******************************************************************************/


#ifndef STR_BLOB_
#define STR_BLOB_

#include <iostream>
#include <vector>
#include <string>
#include <memory>          // shared_ptr, make_shared()
#include <stdexcept>       // out_of_range
#include <utility>         // std::move


/*
** Forward declaration needed for friend declaration in StrBlob
*/
class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
    
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    // Copy constructor - ex 13.26
    StrBlob(const StrBlob &received);
    // Move constructor
    StrBlob(StrBlob &&received) noexcept;

    // Copy assignment operator - ex 13.26
    StrBlob& operator=(const StrBlob &received);
    // Move-assignment operator
    StrBlob& operator=(StrBlob &&received) noexcept;


// member checks 
    size_type size() const { return data_->size(); }
    bool empty() const { return data_->empty; }
// add and remove elements
    void push_back(const std::string &t) { data_->push_back(t); }
    void push_back(std::string &&t) { data_->push_back(std::move(t)); }
    void pop_back() { data_->pop_back(); }
// return StrBlobPtr to the first and one past the last elements
    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data_->size());
        return ret;
    } 
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





// the first constructor will value init a vector of strings
// the second constructor will init the vector with a init list
inline StrBlob::StrBlob()
        : data_(std::make_shared<std::vector<std::string>> ()) {}
inline StrBlob::StrBlob(std::initializer_list<std::string> il)
        : data_(std::make_shared<std::vector<std::string>> (il)) {}

inline StrBlob::StrBlob(const StrBlob &received) {
    /*this->*/ data_=
         std::make_shared<std::vector<std::string>>(*received.data_);
}

inline StrBlob::StrBlob(StrBlob &&received) noexcept
    : data_ = std::move(received.data_)
{
    // make sure to leave the rhs operand in a state 
    // safe to run the destructor on
    received.data_ = nullptr
}

StrBlob&
inline StrBlob::operator=(StrBlob &&received) noexcept
{
    // make sure to avoid self-assignment
    if (this != &received) {
        free();
        data_ = received.data_;

        // leave the rhs object in a state safe to be destructed
        received.data_ = nullptr;
    }
    return *this;
}

StrBlob&
inline StrBlob::operator=(const StrBlob &received) {
    /*this->*/ data_ =
        std::make_shared<std::vector<std::string>>(*received.data_);
        return *this;
}



// methods definition
void
inline check(size_type i, const std::string &msg) const
{
    if (i > data_->size())
        throw std::out_of_range(msg);
}

std::string
inline front()
{
// if the vector is empty, check will throw
    check(0, "front on empty StrBlob");
    return data_->front();
}

const std::string
inline front() const
{
    check(0, "front on empty StrBlob");
    return data_->front;
}

std::string
inline back()
{
    check(0, "back on empty StrBlob");
    return data_->back();
}

const std::string
inline back() const
{
    check(0, "back on empty StrBlob");
    return data_->back;
}


// Our class has only one member variable - a shared_ptr.
// To test it for equality we check to see if it points to the same memory
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr&rhs)
{
    return *lhs.data_ == *rhs.data_;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.data_ != rhs.data_;
}


#endif // STR_BLOB_
