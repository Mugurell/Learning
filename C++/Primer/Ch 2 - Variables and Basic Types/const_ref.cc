/* In mod normal, daca sa zicem ea e definita intr-un header,
** variabila e definita normal in header, iar mai apoi in orice
** fisier care vrea sa foloseasca aceeasi variabila, aceasta va
** fi doar declarata cu extern in fata - ca sa arate ca e 
** definita in alta parte.
**
**********************************
** In cazul variabilelor const:
**********************************
** - daca vrei sa le folosesti in mai multe fisiere, ele 
** trebuiesc redefinite in toate fisierele in care sunt folosite
**  	-> deci sunt locale pentru fiecare fisier in parte.
********** SAU *********
** - definesti respectiva variabila intr-un singur fisier, 
** dar cu extern in fata (extern const int numar = 14;), iar mai
** apoi (asa cum e si normal), poti sa declari (nu definesti) 
** variabila in orice alt fisier in care vrei sa o folosesti dar
** cu keyword-ul extern in fata (extern const int numar;).
**
**************************************************************
** Putem sa cream o const reference pt obiecte care nu-s const
**************************************************************
*/


#include <iostream>

int main()
{
	/* In cazul asta, si r e reference to a const int !!!
	** Iar r e referinta pt constanta 0 !!!!!!!!!!!!!!!!!
	*/
	 const int i = 14, &r = 0;


	/* Eroare. Reference-urile trebuie sa aiba exact acelasi tip
	*/
	//int &rgb = i;


	/* Eroare. Toate const trebuiesc definite si initializate!
	*/
	// const int iii;
	// const int &riii;


	/* Const ref catre orice.
	*/
	const int &r1 = i;
	const int &r2 = 42;
	const int &r3 = r1*r2;
	std::cout << "\ti e " << r1 << "\n\tr2 e " << r2 << "\n\tr3 e " \
			  << r3 << '\n' << std::endl;


	/* Chestia asta merge!!!
	*/
	double dval = 3.14;
	const int &rd = dval;
	std::cout << "const int rd e "<< rd << "\n\t doubleul catre care" \
			  << " rd e referinta e " << dval << '\n' << std::endl;


	/* Elementul catre care se refera const ref poate fi schimbat
	** in mod direct, nu folosindu-se o const ref.
	*/
	int nr = 42;
	int &rnr = nr;
	const int &rnr2 = nr;
	rnr = 0;
	// rnr2 = 0;   // da eroare pt ca vreau sa modific un const
	std::cout << "rnr e " << rnr << "\n\tiar rnr2 e " << rnr2 \
			  << '\n' << std::endl;


	return 0;
}