#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string s1, s2;

	cout << "\nEnter 2 strings:" << endl;
	cin >> s1 >> s2;

	if (s1 == s2)
		cout << "The 2 strings are equal." << endl;
	else {
		s1 > s2 ? cout << s1 << " is bigger than " << s2 << '.' :\
				  cout << s2 << " is bigger than " << s1 << '.';
		cout << endl;
	}

	return 0;										  
}				