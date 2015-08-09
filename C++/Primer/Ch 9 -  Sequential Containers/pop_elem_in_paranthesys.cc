/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 8 iunie 2015, 19:30:17 +0300
**  Last updated:     		---
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
**  Exercise 9.52: Use a stack to process parenthesized expressions. When
**	you see an open parenthesis, note that it was seen. When you see a close
**	parenthesis after an open parenthesis, pop elements down to and including
**	the open parenthesis off the stack. push a value onto the stack to
**	indicate that a parenthesized expression was replaced.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  --- You can write here the execution command & the expected result --- 
**
**  Notes:
**  The solution is copied (:-|) from Mooophie's github.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <stack>


int main()
{
	std::string expression {"My name is (Mugurel)."};
	bool bSeen = false;
	std::stack<char> stk;

	for (const auto &s : expression) {
		if ( s == '(' )
			bSeen = true;
		else if ( s == ')' )
			bSeen = false;

		if (bSeen)
			stk.push(s);
	}

	std::string repstr;
	while (!stk.empty()) {
		repstr += stk.top();
		stk.pop();
	}

	expression.replace(expression.find( "(" )+1, repstr.size(), repstr);

	std::cout << expression << std::endl;	

	return 0;
}