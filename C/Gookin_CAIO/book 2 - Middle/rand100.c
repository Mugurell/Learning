#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LOOP 100

int main()
{

int random , loop;

srand((unsigned)time(NULL));

printf("This are 100 random numbers :\n\n");

for(loop=0 ; loop<LOOP ; loop++)
{
random = rand() %100+1;
printf("%d\t" , random);
}

return 0;
}
