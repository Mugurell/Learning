#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

string hex(unsigned nr, const string hexa);

int main()
{
	const string hexa {"0123456789ABCDEF"};

	cout << "Enter a number to be converted to hex: ";
	unsigned long nr = 0;
	cin >> nr;
	
	string result = hex(nr, hexa);
	if(result[0] == 0)
		cout << "\n0 is 0 in pretty much any numbering system.." << endl;
	else
		cout << nr << " in hexa is " << result << endl;

	return 0;
}

string hex(unsigned number, const string hexa)
{
	string result {};

	// while (number > 0) {
	// 	cout << "**number = " << number << " hexa = " << hexa.size() << endl;
	// 	if(number < hexa.size()) {
	// 		result += hexa[number];
	// 		cout << "**number is "<< number << " result is " << result << endl;
	// 		return result; 
	// 	} else {
	// 		cout << "Am intrat in else" << endl;
	// 		number %= 16;
	// 		cout << "number = " << number << endl;
	// 		result += hex(number, hexa);
	// 		number -= 9;
	// 	}
	// }


	while (1) {
		unsigned first_nr = 0;
		if (number >= 256) {  // 256 in hex is 100 - 3 numbers.
		 	result += hex(number/16, hexa);
		 	cout << "Mi-a returnat " << result << endl;
		 	number %= 16;
		}
		if (number >= hexa.size()) {
			first_nr = number/hexa.size();
			result += hexa[first_nr];
			cout << "number is now " << number << endl;
			number %= hexa.size();
		} else {
			result += hexa[number];
			return result;
		}
	}
}