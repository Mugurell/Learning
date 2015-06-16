//Lingurar Petru-Mugurel, 26-10-2014, moon.c

#include <stdio.h>

int main()

{

float distance=378921.46;
float speed=140;
float duration=distance/speed;
float days;

     printf("The moon is %f kilometers away. \n" , distance);
     printf("At %d kilometers per hour," , speed);
     printf("It would take us %.3f hours to get there. \n" , duration);
     printf("That would mean roughly %.f days. Hella lot! \n" , days=duration/24);

     return(0);

}

