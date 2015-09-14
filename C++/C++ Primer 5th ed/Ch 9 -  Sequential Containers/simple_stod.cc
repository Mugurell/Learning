#include <iostream>
#include <string>


int main()
{
	std::string s = {"pi = 3.14"};
	std::cout << "\nSo we got a nice little string:\n\t" << s
			  << "\n\nIf we're to use stod to convert the numbers in the "
			  << "string into digits,\n we'll have\n\t"
			  << stod(s.substr(s.find_first_of("+-.0123456789")))
			  << "\n\n Pretty nice huh?\n" << std::endl;

	return 0;
}