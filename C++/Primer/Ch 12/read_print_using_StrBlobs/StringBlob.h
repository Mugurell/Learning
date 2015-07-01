/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          30 Jun 2015, 14:32
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
 *  Declaration of a class named StringBlob that will hold a collection of
 *  elements. Unlike the containers, we want Blob objects that are copies of
 *  one another to share the same elements. That is, when we copy a Blob, the
 *  original and the copy should refer to the same underlying elements.
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


#ifndef READ_PRINT_USING_STRBLOBS_STRBLOB_H
#define READ_PRINT_USING_STRBLOBS_STRBLOB_H


#include <iostream>
#include <string>
#include <vector>
#include <memory>           // shared_ptr, make_shared()
#include <stdexcept>        // out_of_range


/*
 * Forward declaration needed for friend declaration in StringBlob
 */
class StringBlobPtr;

class StringBlob {
public:
	friend class StringBlobPtr;
	using SizeType = std::vector<std::string>::size_type;
	StringBlob();
	StringBlob(std::initializer_list<std::string> il);

	SizeType size() const;
	bool isEmpty() const;
	void pushBack(const std::string &temp);
	void popBack();
	StringBlobPtr begin();
	StringBlobPtr end();
	// element access
	std::string& getFirstWord();
	const std::string& getFirstWord() const;
	std::string& getLastWord();
	const std::string& getLastWord() const;
private:
	std::shared_ptr<std::vector<std::string>> data;

	// throw 'errorMessage' if data isn't valid
	void testValidity(SizeType, const std::string&) const;
};


#endif //READ_PRINT_USING_STRBLOBS_STRBLOB_H