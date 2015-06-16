#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string s1 ("Te");
	string s2 = "salut";
	auto c = ' ';
	s1 += ' ' + s2 + c + "lume" + '!';

	cout << '\n' << s1 << '\n' << endl;
}