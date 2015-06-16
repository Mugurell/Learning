#include <iostream>

#define COUT std::cout.width(10);std::cout <<

int main()
{
	long double ld = {3.45654653243};
	int a = {3.45678986754};

	/*
	** Now look at the compile log. narrowing conversion.
	** This only happens when you use curly braces (C11).
	*/

	COUT ld << std::endl;
	COUT a << std::endl;

	return 0;
}