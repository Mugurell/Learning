#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string word;
	char buffer;

	// while (cin >> buffer) {
	// 	cout << "Am citit " << buffer << '\n';
	// 	if (buffer == ' ')
	// 		cout << word << endl;
	// 	word += buffer;
	// }

	while (cin >> word)
		cout << word << endl;

	return 0;
}