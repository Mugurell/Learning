#include <iostream>

int reused = 42;

int main()
{
	int sum = 0;
	int val = 987;

	for (int val = 1; val <= 10; ++val) {
		// the global val is now hidden by this local 'for' one
		std::cout << "val is now " << val << std::endl;
		sum += val;
	}

	std::cout << "\nval is still " << val << std::endl;

	std::cout << "\nSum of 1 to 10 inclusive is " << sum  \
			  << ".\n" << std::endl;

	/*
	** Test for a local reused variable;
	*/
	int reused = 999;
	std::cout << "\nLocal reused is " << reused << '.' << std::endl;

	/*
	** How to request the value of the global variable
	** Only works for variables defined outside of any scope
	** (not even for those defined in main).
	*/
	std::cout << "\nGlobal reused is " << ::reused << '.' << std::endl;
	

	int i = 100;
	sum = 0;
	for (int i = 0; i != 10; ++i)
		sum += i;
	std::cout << "\nI is " << i << " and sum is " << sum  \
			  << ".\n" << std::endl;
	return 0;
}