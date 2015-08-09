#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	cout << "Say something" << endl;

	string new_saying;
	while (getline(cin, new_saying)) {
		for (decltype(new_saying.size()) index = 0 ;
			index < new_saying.size() && !isspace(new_saying[index]);
			++index) {
			auto &ch = new_saying[index];
			if (ch >= 'a' && ch <= 'z')
				ch -= 'a' - 'A';
		}
		cout << new_saying << endl;
	}

	return 0;
}