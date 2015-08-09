#include <iostream>

using std::cout; using std::endl;

int main()
{
	unsigned x (2), y = 0;

	cout << "\nSo first we have x - " << x << " and y - " << y << endl;

	y = (++x, cout << "\nx e acum " << x << endl, ++x, 2*x);
	cout << "\tIar y este " << y << '\n' << endl;

	return 0;
}