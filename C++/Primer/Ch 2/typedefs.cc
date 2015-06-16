/*
** C++11 introduced 'alias declaration' as a new way to define 
** a type alias, beside typedef.
*/

#include <iostream>


int main()
{
	typedef double wages; 		// wages is an alias for double
	typedef wages base, *p;		// base is an alias for double
								// *p is an alias for double *
	wages a = 3;		// double a = 3;
	base b = 4;			// double b = 4;
	p ptr = &a;			// double *ptr = &a;
	std::cout << "\na este " << a << ", b este " << b << \
				 ", iar p este .. " << *ptr << '.' << std::endl;


	using numar = int;			// numar is an alias for int
	numar n = 14;		// int n = 14;
	std::cout << "\nn este.. " << n << ".\n" << std::endl;


	typedef char *pstring;	
	const pstring cstr = 0;	
	/* pstring e un pointer catre char (char *)
	** const pstring == (const char *) - un pointer constant
	**										catre char
	** cstr e un pointer constant catre char  
	*/
	
	const pstring *ps;		
	/* se citeste (const pstring) *ps;  
	** deci avem a (const *char) *ps
	** citit backwards -> ps e un pointer catre un pointer to char
	*/
	
	return 0;
}