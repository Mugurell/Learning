#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLIPS 1000

int main()
{
int numar, flip;
int heads = 0;
int tails = 0;
float tailsp;
float headsp;


srand((unsigned)time(NULL));

printf("Let's see how the coin flips .. \n\n");

for(numar=0 ; numar<FLIPS ; numar++)
{
flip = rand() % 2;

if(flip)
    printf("Heads\t");
else
    printf("Tails\t");

heads +=flip;     //assume heads e 1 (avem random de 0 si 1 (mai putin de 2))
tails = FLIPS - heads;
}

printf("\n\n /There are %d heads", heads);
printf("\n /There are %d tails" , tails);

headsp = (float)heads/FLIPS * 100.0;
tailsp = 100.0 - headsp;
printf("\n\nThe results just came in...\n\tAre you curious..?\n\n");
printf("Heads percentage = %.2f\n" , headsp);
printf("Tails percent = %.2f\n" , tailsp);

return 0;

}
