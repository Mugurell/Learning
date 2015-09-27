#include <iostream>
#include <string>
#include <cctype>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	cout << "Say something:" << endl;

	string new_line;
	while (getline(cin, new_line)) {
		// use a reference to modify the chars in the sequence.
		for(auto &ch : new_line)
			ch = toupper(ch);
		cout << new_line << endl;
	}

	return 0;
}