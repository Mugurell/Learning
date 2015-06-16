#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	cout << "Enter some strings to be concatenated." << endl;
	
	string big, buffer;
	while (getline(cin, buffer))
		big += buffer + ' ';

	cout << "And the concatenated string is.. :\n" << big << endl;

}