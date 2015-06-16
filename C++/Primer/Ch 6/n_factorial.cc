#include <iostream>

unsigned long factorial(int);

int main()
{
	std::cout << "\nThis will just use a s5imple function to test the" \
			  << "\nfactorial of a desired value.." << std::endl;

	std::cout << "\nSo to start, pick a random number: ";
	int nr;
	std::cin >> nr;

	if (nr > 100) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << '\n' << nr << " is just to big to handle right now.." \
				  << "\nTry again? [Y] / [N] : ";
		std::string	 response;
		if (std::cin >> response && (response[0] != 'n' && response[0] != 'N')) {
			std::cout << "\nSo enter a number smaller than 32: ";
			std::cin >> nr;
		} else {
			std::cout << "\nOk then .. \n\t Goodbye!\n" << std::endl; 
			return 0;
		}
	}

	std::cout << "\nCool!\nSo " << nr << " factorial is " << factorial(nr) \
			  << ".\n" << std::endl;

	return 0;
}

unsigned long factorial(int nr)
{
	//unsigned long ret = 1;		// local variable to hold the result as we calculate it
	if (nr > 1)
		return factorial(nr-1) * nr;
	return 1;
//	return ret;
}