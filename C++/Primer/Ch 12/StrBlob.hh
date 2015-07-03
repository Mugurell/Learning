/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          mari 23 iunie 2015, 18:26:55 +0300
**  Last updated:     luni 29 iunie 2015, 22:28:31 +0300
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


/*
** Forward declaration needed for friend declaration in StrBlob
*/
class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    
// member checks 
    size_type size() const { return data_->size(); }
    bool empty() const { return data_->empty; }
// add and remove elements
    void push_back(const std::string &t) { data_->push_back(t); }
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
StrBlob::StrBlob(): data_(std::make_shared<std::vector<std::string>> ()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il):
        data_(std::make_shared<std::vector<std::string>> (il)) {}


void
check(size_type i, const std::string &msg) const
{
    if (i > data_->size())
        throw std::out_of_range(msg);
}


std::string
front()
{
// if the vector is empty, check will throw
    check(0, "front on empty StrBlob");
    return data_->front();
}

const std::string
front() const
{
    check(0, "front on empty StrBlob");
    return data_->front;
}

std::string
back()
{
    check(0, "back on empty StrBlob");
    return data_->back();
}

const std::string
back() const
{
    check(0, "back on empty StrBlob");
    return data_->back;
}


#endif // STR_BLOB_