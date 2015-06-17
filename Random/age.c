#include <stdio.h>

int age(int);

int born, old;

int main()
{

    printf("In what year were you born? %c", 16);
    scanf("%d" , &born);

    printf("\n\nThat would mean you are...\n\t..%d years old !!" , age);
    return 0;
}

int age(int born)
{
    old = 2014 - born;

    return (old);
}
