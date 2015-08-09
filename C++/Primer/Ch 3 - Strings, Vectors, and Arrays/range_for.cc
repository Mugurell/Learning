/*
** The syntactic form is
**
**	for (declaration : expression)
**		statement
** 
** Where: - expression is an object of a type that represents a sequence,
**        - declaration defines the variable that we’ll use to access 
**          the underlying elements in the sequence.
** On each iteration, the variable in declaration is initialized from
** the value of the next element in expression .
*/

#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string read_line;

	cout << "Say something" << endl;
	getline(cin, read_line);

	for (auto ch : read_line)
		cout << ch << endl;

	return 0;
}