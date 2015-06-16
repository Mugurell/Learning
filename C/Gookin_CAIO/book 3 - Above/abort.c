#include <stdio.h>
#include <stdlib.h>   //!necesar pt functia abort
#include <math.h>	  //necesar pt functia sqrt

int main()
{
   float value;

   double answer;

   printf("0! Computer, find me the square root of %c ", 16);
   scanf("%f" , &value);

   if (value < 0.0)
    abort();

   answer = sqrt((double)value);
   printf("\n\nThe computer says the answer is %f\n", answer);

    exit(0);
}
