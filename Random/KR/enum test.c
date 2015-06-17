#include <stdio.h>

int Marcu;                  //! variabilele externe sunt din oficiu initializate cu 0

int main(void)
{
	enum zile {Luni, Marti, Miercuri, Joi, Vineri, Sambata, Duminica};
	int x;
	static int John;        //! variabilele statice sunt din oficiu initializate cu 0

	for(x=Luni; x<=Duminica; x++)
		printf("X este %d\n", x);
		John = 3;
		printf("Marcu este %d sau %d sau %c", Marcu, John+1);



	getchar();

	return 0;
}
