#include <stdio.h>

void peasoup(int *);

int main(void)
{
	int turn;
	//int *head;
	//head = &turn;
	turn = 13;
	
	peasoup(&turn);		//trimit ca argument ce se afla la
						//adresa lui turn continuta de head
						// adica un int
	printf("Ohh no, its %d again", turn);

	getchar();
	return 0;
}

void peasoup(int *green)
{
	while((*green)--)  //cand ajunge la 0 while-ul nu mai merge!!!
					   // v. UNLINE.c
		puts("Bleah!");
	*green = 13 * 51 + 3;
	// Even without returning the pointer 
	// from the function, the value is returned.
	// Pentru ca rezultatul e pus la adresa variabilei..
}