#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	cout << "Say something.." << endl;

	string something;
	while (getline(cin, something)) {
		for(auto ch : something) {
			if(!ispunct(ch))
				cout << ch;
			else 
				;
		}
		cout << endl;
	}
	return 0;
}