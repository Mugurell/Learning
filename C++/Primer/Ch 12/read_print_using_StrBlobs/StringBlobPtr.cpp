/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          30 Jun 2015, 18:22
 *  Last updated:     01 Jul 2015, 18:08 
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
 *  Implementation for the StringBlobPtr class.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *
 *  Notes:
 *  ---
 *
*******************************************************************************
******************************************************************************/


#include "StringBlobPtr.h"


StringBlobPtr::StringBlobPtr()
		: //wordPtr(std::weak_ptr<std::vector<std::string>> ()),
          iCurrentWord(0) {}
StringBlobPtr::StringBlobPtr(StringBlob &stringRead, size_t size)
		: iCurrentWord(size), wordPtr(stringRead.data) {}


/*
 * Because a weak_ptr does not participate in the reference count of its
 * corresponding shared_ptr, the vector to which this StrBlobPtr points might
 * have been deleted. If the vector is gone, lock will return a null pointer.
 * In this case, any reference to the vector will fail, so we throw an
 * exception. Otherwise, check verifies its given index.
 * If that value is okay, check returns the shared_ptr it obtained from lock.
 */
std::shared_ptr<std::vector<std::string>>
StringBlobPtr::testValidity(std::size_t searchedWordNo,
                            const std::string &errorMessage) const {
	// is the vector still around
	std::shared_ptr<std::vector<std::string>> vectorPtr = wordPtr.lock();
	if (!vectorPtr)
		throw std::runtime_error("Unbound StringBlobPtr!");
	if (searchedWordNo > vectorPtr->size())
		throw std::out_of_range(errorMessage);

	return vectorPtr;   // otherwise return a shared_ptr to the vector
}

/*
 * If check succeeds, p is a shared_ptr to the vector to which this
 * StringBlobPtr points. The expression (*vectorPtr)[iCurrentWord] dereferences
 * that shared_ptr to get the vector and uses the subscript operator to fetch
 * and return the element at iCurrentWord.
 */
std::string&
StringBlobPtr::getCurrentWord() const {
	std::shared_ptr<std::vector<std::string>>
			vectorPtr = testValidity(iCurrentWord, "Dereference past end!");
	return (*vectorPtr)[iCurrentWord];
}

/*
 * prefix: will return a reference to the incremented object
 */
StringBlobPtr&
StringBlobPtr::incrementWordPointer() {
	// if iCurrentWord already points past the end of the container
	// can't increment it
	testValidity(iCurrentWord, "Increment past end of the StringBlobPtr!");
	++iCurrentWord;     // advance the current state
	return *this;
}
