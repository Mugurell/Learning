/*
**  Exercise 3.17: 
** Read a sequence of words from cin and store the values in a vector. 
** After you’ve read all the words, process the vector and change each word 
** to uppercase. Print the transformed elements, eight words to a line.
*/

author	


#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin; using std::cout; using std::endl; 
using std::string; using std::vector;

int main()
{

	cout << '\n';

	/*
	** Read words (groups of letters separated by spaces) 1 by one and store
	** them in the vector (string container) prop until the word "stop".
	*/
	vector<string> prop;
	string word;
	while (cin >> word) {
		if (word == "stop")
			break;
		else {
			prop.push_back(word);
		}
	}

	/*
	** Change all letters to uppercase.
	** Note the reference. For modifying each character.
	*/
	for (auto &words : prop)
		for (auto &ch : words)
			if (ch >= 'a' && ch <= 'z')
				ch -= 'a' - 'A';

	/* 
	** Print maximum 'word_counter <= 8' words on a single line.
	** Membrul size o sa fie de tipul vector<string>::size_type.
	*/
	decltype(prop.size()) word_counter {0};
	for (auto wordd : prop) {
		++word_counter;
		if (word_counter <= 8)
			cout << ' ' << wordd;
		else {
			cout << endl;
			word_counter = 0;
		}
	}

	cout << '\n' << endl;


/*
** Logica de aici e gresita pt ca prop tine cuvinte, nu litere!

	unsigned word_counter {0};
	unsigned elem_counter {0};
	decltype(prop.size()) len = prop.size();
	while (elem_counter < len) {
		for (char chr : prop) {
			if (isspace(chr))
				++word_counter;
			if (word_counter == 8)
				cout << '\n';
			if (chr == '\n') {
				++elem_counter;
				continue;
			}
			++elem_counter; 
			cout << chr;
		}
	}
*/

	return 0;
}
