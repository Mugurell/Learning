#include <iostream>
#include <string>
#include "Person.hh"

int main()
{
	Person a("Gheorghe", "Grivita");
	std::cout << "So we have " << a.name << " which lives in " << a.address \
			  << '.' << std::endl;

	std::cout << "Do you want to add another person?" << std::endl;

	Person b;
/*	std::cout << "Enter it's name:\n\t";
	std::cin >> b.getName();
	std::cout << "Now it's address:\n\t";
	std::cin >> b.getAddress();*/
	std::cout << "Enter it's name and it's address:" << std::endl;
	read(std::cin, b);

	std::cout << "So now we have another person:" << std::endl;
	print(std::cout, b);

	std::cout << "Another? Okay..\nShoot:" << std::endl;
	Person c(std::cin);
	std::cout << "And the final person is.." << std::endl;
	print(std::cout, c);
	
	std::cout << std::endl;
	return 0;
}