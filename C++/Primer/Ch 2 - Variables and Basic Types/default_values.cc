#include <iostream>

std::string globagl_str;
int global_int;

int main()
{
	int local_int;
	std::string local_string;

	std::cout << "Globals:\n" << '\t' << '.' << globagl_str \
			  << ".\n\t." << global_int << '.' << std::endl;
	std::cout << "\nLocals:\n" << '\t' << '.' << local_string \
			  << ".\n\t." << local_int << '.' << std::endl;
}	