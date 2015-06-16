#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLIPS 10000

int main()
{
   int coin, loop;
   int total_heads=0;
   float hpercent, tpercent;

   /*int raspuns = 0;

   printf("Ai castigat vreodata la loto?");
   scanf("%d" , &raspuns);

   srand((unsigned)raspuns);*/

   srand((unsigned)time(NULL));

   for(loop=0; loop<=FLIPS; loop++)
   {
       coin = rand() % 2;   //numere random 0-1  (2 numere)
       /*Assume 1 is heads and 0 is tails*/

       total_heads += coin;         //total_heads = total_heads = coin
       if(coin)
        printf("Heads\t");
       else
        printf("Tails\t");
   }
    hpercent = (float)total_heads/FLIPS*100;
    tpercent = 100.0 - hpercent;    //100.0 face ca compilerul sa stie ca e floating - tot un fel de typecast...
    printf("Total Flips: %d\nHeads: %.2f\nTails: %.2f\n" , FLIPS , hpercent , tpercent);

    return 0;
}
