#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
	cout << "\nNow I'm gonna print all numbers from 1 to 10" \
		 << "\n and at the end print the sum of them:" << endl;

	int x = 1;
	int sum = 0;
	while (x <= 10) {
		sum += x;
		cout << "\t" << x++ << endl;
	}

	cout << "And their sum is .. " << sum << ".\n" << endl;

	return 0;
}