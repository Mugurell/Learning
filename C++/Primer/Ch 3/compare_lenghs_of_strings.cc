#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main(void)
{
	cout << "Enter 2 strings:" << endl;
	string s1, s2;
	cin >> s1 >> s2;

	if (s1.size() == s2.size())
		cout << "Both strings have the same lenght!" << endl;
	else {
		s1.size() > s2.size() ? cout << "First string is bigger." :\
								cout << "Second string is bigger.";
		cout << endl;
	}

	return 0;
}