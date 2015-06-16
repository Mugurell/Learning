//Lingurar Petru-Mugurel, 26-10-2014, moon.c

#include <stdio.h>

int main()

{

float distance=378921.46;
float speed=140;
float duration=distance/speed;
float days = duration/24;
float *d;

    d = &distance;
     printf("The moon is %f kilometers away. \n" , *d);

     d = &speed;
     printf("At %.2f kilometers per hour," , *d);

     d = &duration;
     printf("It would take us %.3f hours to get there. \n" , *d);

     d = &days;
    printf("That would mean roughly %.f days. Hella lot! \n" , *d);

     return(0);

}


