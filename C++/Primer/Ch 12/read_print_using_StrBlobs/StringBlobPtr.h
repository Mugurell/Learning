/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          30 Jun 2015, 17:48
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
 *  A companion pointer class for our StringBlob class.
 *  Our pointer class, which we’ll name StringBlobPtr, will store a weak_ptr
 *  to the data member of the StringBlob from which it was initialized.
 *  By using a weak_ptr, we don’t affect the lifetime of the vector to which a
 *  given StringBlob points. However, we can prevent the user from attempting
 *  to access a vector that no longer exists.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  StringBlobPtr will have two data members: wordPtr, which is either null or
 *  points to a vector in a StringBlob; and iCurrentWord, which is the index of
 *  the element that this object currently denotes. Like its companion
 *  StringBlob class, our pointer class has a testValidity member to verify
 *  that it is safe to dereference the StringBlobPtr:
 *
 * If you give default values for parameters, they are filled in at the caller.
 * So they have to be in the function's declaration, because this is what the
 * callers need to see. If you had to repeat them at the definition it would be
 * redundant and more hassle to maintain.
 * (see the second constructor)
*******************************************************************************
******************************************************************************/



#include <iostream>


#ifndef READ_PRINT_USING_STRBLOBS_STRINGBLOBPTR_H
#define READ_PRINT_USING_STRBLOBS_STRINGBLOBPTR_H


#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <memory>
#include <stdexcept>

#include "StringBlob.h"


// StringBlobPtr throws an exception on attempts to access non-existed elements
class StringBlobPtr {
public:
	StringBlobPtr();
	StringBlobPtr(StringBlob &stringRead, size_t size = 0);

	std::string& getCurrentWord() const;
	StringBlobPtr& incrementWordPointer();      // prefix version
private:
	// testValidity returns a shared_ptr to the vector if the check succeeds
	std::shared_ptr<std::vector<std::string>>
		testValidity(std::size_t, const std::string&) const;

	// store a weak_ptr which means the underlying vector might be destroyed
	std::weak_ptr<std::vector<std::string>> wordPtr;
	std::size_t iCurrentWord;       // current position within the array
};


#endif //READ_PRINT_USING_STRBLOBS_STRINGBLOBPTR_H