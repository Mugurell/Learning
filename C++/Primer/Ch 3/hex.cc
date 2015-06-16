#include <iostream>
#include <string>

using std::cin;  using std::cout; using std::endl; using std::string;

int main()
{
	const string hexadigits {"0123456789ABCDEF"};

	cout << "hexadigits.size() = " << hexadigits.size() << endl;

	cout << "Enter a series of numbers between 0 and 15 " \
		 << "separated by spaces. Hit Enter when finished." \
		 << endl;

	string result;
	string::size_type n;

	while (cin >> n) 
		if(n < hexadigits.size())
			result += hexadigits[n];

	cout << result << endl; 

	return 0;
}