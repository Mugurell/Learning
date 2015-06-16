#include <iostream>

using std::cin;
using std::cout; using std::endl;

int main()
{
	cout << "\nEnter 2 numbers:\n\t";
	int v1, v2;
	cin >> v1;
	cout << '\t';
	cin >> v2;
	cout << "Sum of " << v1 << " and " << v2 << " is " 
		 << v1+v2 << ".\n" << endl;

	return 0;
}