#include <iostream>

int main()
{
	int nr {-8};
	int nr2 = nr >> 2;
	int nr3 = ~nr;

	std::cout << '\n' << nr << " >> 2 = " << nr2 << '\n' << std::endl; 
	std::cout << '~' << nr << " = " << nr3 << '\n' << std::endl; 

	std::cout << 1LU << std::endl;



	return 0;
}