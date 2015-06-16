#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	cout << "Say something.." << endl;

	string something {};
	// getline reads until \n but discards it and keeps whats in front
	while (getline(cin, something)) {
		for(auto ch : something) {
			if (isalpha(ch))
				cout << "X";
			else
				cout << ch;
		} 

/*		unsigned int x = 0;
		for(char ch = something[x]; ch != '\0' ; x++) {
			ch = something[x];
			if(isalpha(ch))
				cout << 'X';
			else
				cout << ch;
		}*/

/*	unsigned x = 0;
		while (something[x] != '\0') {
			if (isalpha(something[x]))
				cout << 'X';
			else
				cout << something[x];
			x++;
		}*/

		cout << endl;
	}

	return 0;
}