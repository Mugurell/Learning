/*
** The compare operators (which are case-sensitive) works in two ways:
**		1) compare to see which is longer in lenght
**		2) compare based on their ASCII values;
** The most important is the 2): Even if the first string is longer in
** lenght, the second string will be bigger if it's ASCII value is >.
*/

#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string a = "hello";
	string b = "Hello World!";
	string c = "Heya!";

	cout << "So we have 3 strings:\n\t" << a << "\n\t" << b \
		 << "\n\t" << c << ".\n" << endl;
	cout << "Which one is bigger you ask?" << endl;

	a > b ? cout << "A is bigger than B." :\
			cout << "B is bigger than A." ;
			cout << endl;
	a > c ? cout << "A is bigger than C." << :\
			cout << "C is bigger than A." << ;
			cout << endl;

	b > c ? cout << "B is bigger than C." << :\
			cout << "C is bigger than B." << ;
			cout << endl;			

	return 0;
}