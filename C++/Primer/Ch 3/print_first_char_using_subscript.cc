#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	cout << "Say something" << endl;
	
	string new_saying;
	getline(cin, new_saying);

	if (!new_saying.empty())
		cout << "The first char is " << new_saying[0] << endl;


	return 0;
}