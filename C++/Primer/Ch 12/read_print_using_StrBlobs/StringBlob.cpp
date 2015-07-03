/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          30 Jun 2015, 17:24
 *  Last updated:     01 Jul 2015, 18:11
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
 *  Implementation for the StringBlob class.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  For why I included both StringBlob.h and StringBlobPtr.h see
 *  http://stackoverflow.com/questions/13594549/base-class-has-incomplete-type
 *
 *  Showstopper bug in read() in line 'inputFileText.pushBack(eachWord).
 *  Seems like I get a segmentation fault because the shared_ptr (member of
 *  inputFileText - StringBlobPtr) hasn't allocated enough space for the vector
 *  to grow.
 *  strikeout ATM don't know how to resolve this. /strikeout
 *  Resolved by defining a constructor that can instantiate the StrBlob with
 *  a value initialized vector of strings.
 *  Previously the first constructor was:
 *          StringBlob::StringBlob() = default;
 *
*******************************************************************************
******************************************************************************/



#include "StringBlob.h"
#include "StringBlobPtr.h"


/*
 * StringBlob constructors implementation:
 */
StringBlob::StringBlob()
        : data(std::make_shared<std::vector<std::string>> ()) {}
StringBlob::StringBlob(std::initializer_list<std::string> il)
        : data(std::make_shared<std::vector<std::string>> (il)) {}


/*
 * Private methods implementation:
 */
void
StringBlob::testValidity(SizeType SearchedWordNo,
                         const std::string &errorMessage) const {
    if (SearchedWordNo > data->size())
        throw std::out_of_range(errorMessage);
}


/*
 * Public methods implementation
 */
std::string&
StringBlob::getFirstWord() {
    testValidity(0, "StringBlob is empty!");
    return data->front();
}


const std::string&
StringBlob::getFirstWord() const {
    testValidity(0, "StringBlob is empty!");
    return data->front();
}


std::string&
StringBlob::getLastWord() {
    testValidity(0, "StringBlob is empty!");
    return data->back();
}


const std::string&
StringBlob::getLastWord() const {
    testValidity(0, "StringBlob is empty!");
    return data->back();
}


StringBlobPtr
StringBlob::begin() { return StringBlobPtr(*this); }


StringBlobPtr 
StringBlob::end() {
    auto ret = StringBlobPtr(*this, data->size());
    return ret;
}


void
StringBlob::popBack() { data->pop_back(); }


void
StringBlob::pushBack(const std::string &temp) { data->push_back(temp); }


bool
StringBlob::isEmpty() const { return data->empty(); }


StringBlob::SizeType
StringBlob::size() const { return data->size(); }