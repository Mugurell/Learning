#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main(void)
{
	string line;

	/*
	** empty() returns TRUE if it's left operator is emty
	** 			   and FALSE if -||- is not (contains a char)
	*/
	while (getline(cin, line))
		if (!line.empty())
			cout << line << endl;

	return 0;
}