/*
** Interesting fact:
** When we deal with a constant pointer we refer to it as
**				a top-level constant
** When we deal with an constant object to which the pointer
** ..points we refer to it (to that object) as
** 				a low-level constant
*/

#include <iostream>

int main()
{
	/*
	** Pentru ca unui pointer constant nu poti sa-i schimbi 
	** valoarea (adresa de mem), trebuie initializat din prima.
	*/
	// int *const p32; // o sa dea eroare ca nu a fost initializat.
	// const int gogu; //  -- || --

	/*
	** A constant pointer to a plain int
	** The content of the pointer (mem adress) can't be changed.
	*/
	int db = 31;
	int db2 = 54;
	int *const ptd = &db;
	//ptd = &db2; 	// assignment of read only variable 'ptd'


	/*
	** A constant pointer to a constant int.
	** Nor the int, nor the ptr canbe changed.
	*/
	const int nr = 43;
	const int *const pnr = &nr;

	/*
	** Invalid conversion from 'int*' to 'const int*'
	*/
	// int v1 = 0;
	// const int *const p1 = v1;

	int v1 = 1;
	const int v2 = 2;
	int *p1 = nullptr;
	const int *p2 = &v2;
	int *const p3 = &v1;
	const int *const p4 = &v2;
	p2 = p1;	// merge pt ca pot sa-l fac pe p1 const;
	//p1 = p2;	// nu merge pt ca p2 e const, si p1 nu !!!;
	p1 = p3;	// merge pt ca poti ignora top-level const;
	p2 = p4;	// -- || --


	return 0;
}