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
 *  Implementation file for the templated BlobPtr class.
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


#include <stdexcept>      // std::out_of_range



template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr::check(std::size_t pos,
                                              std::string &message) const
{
    if (pos > curr)
        throw std::out_of_range(msg);
    else
        return std::make_shared<std::vector<T>>(wptr.lock()->at(pos));
}


template <typename T>
inline BlobPtr<T>::operator*() const
{
    auto p = check(curr, "dereference past end");
    return p->at(curr);
}


// prefix: return the incremented/decremented object
template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator--()
{
    // check to see if the operation is valid
    auto p = check (--curr, "allready the first element");
    return --*this;
}

template <typename T>
inline BlobPtr<int>& BlobPtr<T>::operator++()
{
    check(++curr, "allready the last element");
    return ++*this;
}


// postfix: increment/decrement the object but return the unchanged value
template <typename T>
inline BlobPtr<T> BlobPtr<T>::operator--(int)
{
    // no check needed here; the call to prefix increment will do the check
    BlobPtr ret  = *this;       // save the current value
    --*this;        // advance one element; prefix-- checks the decrement
    return ret;     // return the saved state
}

template <typename T>
inline BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}
