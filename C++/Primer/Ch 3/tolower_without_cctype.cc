#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	cout << "Say something:" << endl;

	string new_saying;
	while (getline(cin, new_saying)) {
		for (auto &ch : new_saying)
			if(ch >= 'A' && ch <= 'Z')
				ch += 'a' - 'A';
		cout << new_saying << endl;
	}

	return 0;
}