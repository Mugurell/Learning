#include <stdio.h>

float baby(float food);

int main()
{
    float input, output;

    printf("Enter the quantity you plan on feeding the baby %c ", 16);
    scanf("%f", &input);
    while(getchar() != '\n')
        continue;



    output = baby(input);
//!return(poop)=baby(quantity %f)



    printf("\n\n\tAccording to the computer, baby will\n");
    printf("produce %.2f material as output.\n" , output);

    return 0;
}


float baby(float food)
{
    float poop;

    poop = 1.217*food;

    return(poop);
}
