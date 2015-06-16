#include <iostream>

int main()
{
	int i = 13, *pi = &i, **ppi = &pi;

	std::cout << "The value of i is " << i << std::endl;
	std::cout << "The value of pi is " << pi  \
			  << "\n\taddress at which is " << *pi << std::endl;
	std::cout << "The value of ppi is " << ppi	\
			  << "\n\taddress at which is " << *ppi 	\
			  << "\n\taddress of which is " << **ppi << std::endl;

	return 0;
}