/*
** A constant expression is a variable which:
**		- is defined as const (ex const int);
**		- it's initializer is a const known at compile time;
** 	-> for example: const int = 20.
**
** C 11 introduces ** constexpr **
** declaring a variable as constexpr will ensure the compiler
** will evaluate them at compile time to make sure they're const.
**
** This new constexpr declarations should be used when you intend
** to use a const expression.
*/

#include <iostream>

int main()
{
	constexpr int mf = 20;
	constexpr int limit = mf + 1;
	constexpr int sz = sizeof(mf);

	std::cout << "\nmf is " << mf << "\nlimit is " << limit \
			  << "\nsz is " << sz << ".\n" << std::endl;

/*
** It's important to know that when we define a pointer in a 
** constexpr declaration, the constexpr specifier applies to
** the pointer, not to the type of the pointee!
!!! constexpr imposes top-level const on the object it defines!!!
*/
	/* p is a pointer to a const int */
	const int *p = nullptr;
	// p = &mf;   - asta merge

	/* q is a constant pointer to an int */
	constexpr int *q = nullptr;
	// q = &mf;	  - asta da eroare: assignement of r-o variab.

	/* a constant pointer to a constant int */
	/*constexpr int x = 10;
	constexpr const int *z = &x;	// ciudat...*/

	std::cout << "p is " << p << " and q is " << q << std::endl;

	return 0;
}