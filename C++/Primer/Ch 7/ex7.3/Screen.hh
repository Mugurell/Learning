/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 22 mai 2015, 20:02:51 +0300
**  Last updated:     vineri 22 mai 2015, 22:19:13 +0300
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**	 (g++ 5.1)		  -Woverloaded-virtual -Winvalid-pch -Wcast-align
**					  -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**					  -Wmissing-format-attribute -Wmissing-include-dirs  
**					  -Wredundant-decls -Wswitch-default -Wswitch-enum  
**
**  Execution:    ./...
**
**  Description:
**	Exercise 7.23: Write your own version of the Screen class.
**	Exercise 7.24: Give your Screen class three constructors: a default
**	constructor; a constructor that takes values for height and width and
**	initializes the contents to hold the given number of blanks; and a
**	constructor that takes values for height, width, and a character to use
**	as the contents of the screen.
**	Exercise 7.25: Can Screen safely rely on the default versions of copy and
**	assignment? If so, why? If not, why not?
**	Exercise 7.26: Define Sales_data::avg_price as an inline function.
**	Exercise 7.27: Add the move, set, and display operations to your
**	version of Screen. Test your class by executing ".." - test.cc.

**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**	- A const member function that returns *this as a reference should have a
**	return type that is a reference to const.
**	The calling member will be const when the function is not supposed to
**	modify it's initial elements!!!
**  - 7.26 referes to an ex from a previous section. Will do there.
**
*******************************************************************************
******************************************************************************/


#ifndef _$creen_
	#define $creen_

	#include <string>
	#include <vector>
	#include <iostream>

	struct Screen {
	public:
		typedef std::string::size_type pos;

		// function constructors
		Screen() = default;
		Screen(pos ht, pos wd, char c): height(ht), width(wd), \
										contents(ht * wd, c) { }
		// contents(ht * wd, c) == for ex contents(100, 'x')
		// will be a string of 100 chars, all 'x';
		Screen(pos ht, pos wd): height(ht), width(wd), \
								contents(ht * wd, ' ') { };
		
		// const member function, overloaded, implicitly inline
		char get() const { return contents[cursor]; }

		// const member function, overloaded,
		// explicitly inline - because not defined ( {} ) ;-)
		inline char get(pos ht, pos wd) const;

		// Will be made inline later.
		Screen& set(char c);
		Screen& set(pos r, pos col, char ch);
		Screen& move(pos r, pos c);

		// This two are overloaded because one is a const member function !
		// Also because it is a const m. f. and returns *this it will have a
		// const return !!! See Notes above !
		Screen& display(std::ostream&);
		const Screen& display(std::ostream&) const;

	private:
		void do_display(std::ostream &os) const { os << contents; }

		pos cursor = 0;
		pos height = 0, width = 0;
		std::string contents;
	};


#endif	