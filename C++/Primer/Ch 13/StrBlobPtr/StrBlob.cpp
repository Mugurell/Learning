/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          18 Jul 2015, 09:20:07:850
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
 *
 *  Execution:    ./...
 *
 *  Description:
 *  Implementation file for the StrBlob class.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  ---
 *
*******************************************************************************
******************************************************************************/



#include "StrBlob.h"


// The first constructor will value initialize a vector of strings.
// The second constructor will initialize the vector from a initializer list.
StrBlob::StrBlob()
        : data_(std::make_shared<std::vector<std::string>> ()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il)
        : data_(std::make_shared<std::vector<std::string>> (il)) {}

StrBlob::StrBlob(const StrBlob &received) {
    this-> data_= std::make_shared<std::vector<std::string>>(*received.data_);
}

StrBlob&
StrBlob::operator=(const StrBlob &received) {
    this->data_ = std::make_shared<std::vector<std::string>>(*received.data_);
    return *this;
}



// methods definition
void
StrBlob::check(size_type i, const std::string &msg) const
{
    if (i > data_->size())
        throw std::out_of_range(msg);
}

std::string&
StrBlob::front()
{
// if the vector is empty, check will throw
    check(0, "front on empty StrBlob");
    return data_->front();
}

const std::string&
StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data_->front;
}

std::string&
StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data_->back();
}

const std::string&
StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data_->back;
}


void StrBlob::pop_back()
{ data_->pop_back(); }

void StrBlob::push_back(const std::string &t)
{ data_->push_back(t); }

bool StrBlob::empty() const
{ return data_->empty; }

size_type StrBlob::size() const
{ return data_->size(); }

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data_->size());
    return ret;
}

StrBlobPtr StrBlob::begin()
{ return StrBlobPtr(*this); }