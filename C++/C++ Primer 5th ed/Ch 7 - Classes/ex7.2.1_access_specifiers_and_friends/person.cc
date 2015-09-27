#include <iostream>
#include <string>
#include "Person.hh"

int main()
{
	std::cout << "So here is ";
	Person a("John", "London");
	print(std::cout, a) << std::endl;

	std::cout << "\nDo you want to hook him up with someone?" << std::endl;
	std::cout << "Whom that might be?: [name] from [city]:" << std::endl;
	Person b(std::cin);
	print(std::cout, b) << "... Cool!" << std::endl;

	std::cout << "Let's say that after a few years they will have a kid" \
			  << "\nWhat woud his/her name be?: [name]:" << std::endl;
	std::string name_buffer;
	std::cin >> name_buffer;
	Person c(name_buffer);

	std::cout << "\nCool! So their familly will be composed of\n\t" ;
	print(std::cout, a) << std::endl << '\t';
	print(std::cout, b) << std::endl;
	std::cout << "And\n\t";
	print(std::cout, c) << ".. their home probably..\n" << std::endl;

	return 0;
}