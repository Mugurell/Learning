/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          11-Aug-15, 06:16 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  ---
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
********************************************************************************
*******************************************************************************/



#ifndef BLOB_BLOBPTR_H
#define BLOB_BLOBPTR_H


#include <shared_ptr>
#include <vector>
#include <string>
#include <memory>       // weak_ptr

#include "Blob.h"


template <typename T> class BlobPtr {
public:
    BlobPtr() : curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    T& operator*() const;

    BlobPtr& operator--();      // prefix operators
    BlobPtr& operator++();
    BlobPtr& operator--(int);   // postfix operators
    BlobPtr& operator++(int);

private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<T>> check(std::size_t,const std::string&) const;
    // store a weak_ptr - the undeerlying vector might be destroyed
    std::weak_ptr<std::vector<T>> wptr;
    // current position within the array
    std::size_t curr;

};


#include <BlobPtr.tpp>


#endif //BLOB_BLOBPTR_H
