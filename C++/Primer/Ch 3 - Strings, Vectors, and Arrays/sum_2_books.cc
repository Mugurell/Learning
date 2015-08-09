#include <iostream>
#include "Struct_data.hh"

using std::cin; using std::cout; using std::endl;

int main()
{
	cout << "Enter the data for 2 books (ISBN, nr sold, price):" << endl;
	struct Books b1, b2;
	cout << '\t';
	cin >> b1.isbn >> b1.nr >> b1.price;
	cout << '\t';
	cin >> b2.isbn >> b2.nr >> b2.price;

	if (b1.isbn == b2.isbn) {
		unsigned nr_total = b1.nr + b2.nr;
		float price_total = (b1.price * b1.nr) + (b2.price * b2.nr);
		if (nr_total == 0)
			cout << "\nSo there weren't any books sold...\n" << endl;
		else
			cout << "\nSo in total there were " << nr_total \
				 << " books sold." \
				 << "\nAnd with an average price of $" \
				 << price_total/nr_total \
				 << " we gathered $" << price_total << ".\n" << endl; 
	} else {
		cout << "\nThe books must have the same ISBN!\n" << endl;
	}

	return 0;
}