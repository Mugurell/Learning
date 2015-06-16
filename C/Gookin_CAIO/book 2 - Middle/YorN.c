#include <stdio.h>

int main()
{
    int unsigned value;    //poti sa pui orice numar cu - (minus) ...

    do
    {
        printf("Enter a value greater than 20: ");
        scanf("%d" , &value);
    } while (value>20);

    return 0;
}
