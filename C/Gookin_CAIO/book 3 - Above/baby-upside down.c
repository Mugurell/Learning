#include <stdio.h>

float baby(float food)
{
    float poop;

    poop = 1.217*food;

    return(poop);
}

int main()
{
    float input,output;

    printf("Enter quantity you plan on feeding the baby %c " , 16);
    scanf("%f" , &input);
    while(getchar() != '\n')
        continue;

    output = baby (input);

    puts("\n\n\tBased on many, many calculations made by this awesome pc.. ");
    puts("based on this diet..");
    printf("\tthe baby will produce %.2f waste materials!\n\n" , output);

    getchar();

    return 0;
}
