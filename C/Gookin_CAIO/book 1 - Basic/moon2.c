//Lingurar Petru-Mugurel, 26-10-2014, moon2.c

#include <stdio.h>
#define SPEED 140
#define DISTANCE 378921.46 

int main()

{
float duration=DISTANCE/SPEED;
float days;

     printf("The moon is %.2f kilometers away. \n" , DISTANCE);
     printf("At %d kilometers per hour," , SPEED);
     printf("It would take us %.3f hours to get there. \n" , duration);
     printf("That would mean roughly %.f days. Hella lot! \n" , days=duration/24);

     return(0);

}
