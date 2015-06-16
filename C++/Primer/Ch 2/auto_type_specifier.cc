#include <iostream>

int main()
{
	auto i = 13, *p = &i;
	std::cout << "\nI este " << *p << ".\n" << std::endl;

	int *&r = p;
	auto a = *r;
	std::cout << "A este " << a << ".\n" << std::endl;


	/*
	** Ordinarily top-level constants are ignored
	** while low-level constants are kept.
	*/
	const int ci = i, &cr = ci;
	auto b = ci;		// b is an int
	auto c = cr;		// c is an int
	auto d = &i;		// d is a pointer to int
	auto e = &ci;		// e is a pointer to a constant int 
						// (& of a const object is low-level const)
	const auto f = &ci;	// f is a const pointer to a const int


	auto &g = ci;		// g is a const int& bound to ci
	//auto &h = 42;		// error: cannot bind a plain ref to a literal
	const auto &j = 42;	// ok !

	//auto &n = i, *p2 = &ci; 	// error: n is a int&
								// while p2 is a const int*


	return 0;
}