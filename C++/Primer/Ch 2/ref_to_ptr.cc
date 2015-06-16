#include <iostream>

int main()
{

	int i = 40, *pi;
	/*
	** Pt reference tre sa ii zici exact tipul.
	** In cazul asta e pointer catre int. int *. Hance.. 
	*/

	int *&rpi = pi;
	rpi = &i;

	std::cout << "I is " << i << std::endl;
	std::cout << "rpi is " << *rpi << std::endl;

	return 0;
}