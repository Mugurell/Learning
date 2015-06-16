#include <iostream>
#include <string>
#include <cctype>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string newline;
	// cnt va fi acum de tipul std::size_type.
	// De ce? Nush... Asa era ex in carte....
	decltype(newline.size()) cnt = 0;

	cout << "Say something:" << endl;

	while (getline(cin, newline)) 
		for (auto ch : newline) 
			if (isupper(ch))
				cnt++;
		
	cout << "There were " << cnt << " upper-case letters." << endl;
	
}