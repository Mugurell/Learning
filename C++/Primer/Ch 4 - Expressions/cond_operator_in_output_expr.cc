#include <iostream>

int main()
{
	std::cout << "\nWhat was your average in the highschool ? : ";

	unsigned avg;
	std::cin >> avg;
	std::cin.clear();
	while(std::cin.get() != '\n');

	std::cout << (avg > 90 ? "\tBravos!" : \
	 						  avg > 75 ? "\tOkeish.." : \
	 						  			  avg >= 50 ? "\tPass." : "\tReally?")\
			  << '\n' << std::endl;

	return 0;
}