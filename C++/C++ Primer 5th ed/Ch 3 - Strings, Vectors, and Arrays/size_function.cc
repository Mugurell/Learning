#include <iostream>
#include <string>

#define CLEAN while (cin.get() != '\n')

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	cout << "Enter the minimum lenght for the line you want" \
		 << "\n me to store and print: ";
	unsigned max;
	cin >> max;

	cout << "Now let's give it a try.." << endl;
	// char ch;
	// cin >> ch;
	CLEAN;
	string buffer;
	while (getline(cin, buffer)) {
		/*
		** size returns an unsigned string::size_type, so any variable
		** which has to hold this must be defined string::size_type or:
		*/
		auto len = buffer.size();
		if (len >= max) 
			cout << '\t' << buffer << endl;
		else 
			cout << '\t' << "Too few characters! (" << len \
				 << ')' << endl;
	}

	return 0;
}