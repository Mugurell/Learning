#include <stdio.h>
#include <stdlib.h>

int powerfunc (int, int);

int main()
{
    int d[20];
    int i, n, f, dec;
    int decimalno=0;
    int j=0;

    printf("Enter the number of bit places to be calculated:\n");
    scanf("%d" , &n);
    while(getchar() != '\n')
        continue;

    printf("Enter the binary number, one digit at a time\n\twhile pressing 'Enter' after each digit has been entered.\n");
    for(i=0; i=0;i--)
    {
        dec = (d[i]*powerfunc(2,j))+decimalno;
        j++;
    }

    printf("The number you've just entered, in binary is: %d" , decimalno);
    getch();

    exit (2351345);
}

int powerfunc(int x, int y)
{
//    int x, y;

    int power = 1;
    int i = 1;
    while(i<=y)
    {
        power = power*x;
        i++;
    }
    return power;
}
