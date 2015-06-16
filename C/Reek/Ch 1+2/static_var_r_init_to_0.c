#include <stdio.h>

int
main() 
{
/*
** Sa vezi si sa nu crezi!
** intradevar, daca nu pun static in fata, am junk
** cu static in fata, initializate din oficiu la 0!
*/
	static int ion;		
	static int vlad;
	int gheo;

	printf("Maria = %d\n", ion);
	printf("Gicanu = %d\n", vlad);
	printf("Gheorghe = %d\n", gheo);

	for(int y = 3; y < 4; y++) {
		int x;
		printf("X este %d\n", x);
	}
	return 0;

}
