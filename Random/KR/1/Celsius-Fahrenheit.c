#include <stdio.h>

float conversion (int);

int main()
{
    int cels;

    cels = 300;

    /*     codul original va fi inlocuit de o functie

    while(cels>0){
        fahr = 9.0/5.0 *cels + 32;
        printf("%6d - %4.2f\n", cels, fahr);
        cels -=10;
    }
    */
    while (cels > 0)
    {
    	printf("%6d - %4.2f\n", cels, conversion(cels));
    	cels -= 10;
    }

        getchar();

    return 0;
}


float conversion(int cels)
{
	float fahr = 9.0/5.0 *cels + 32;

	return(fahr);
}