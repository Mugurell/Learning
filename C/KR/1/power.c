#include <stdio.h>

//function prototype
int power(int, int);   //! functia power cu 2 int ca parametri ce returneaza un alt intreg


int
main()
{
    int i;

    puts("Putere");
    puts("  (n)  2 la n  -3 la n");
    puts("--------------------------------------");

    for (i = 0; i < 10; i++)
        printf("%4d \t %-2d  \t  %-3d \n", i, power(2, i), power(-3, i));
    											// (2,i)	si   (-3,i) sunt argumente pentru functia power!!!
 /**************************************************************************************
 *We will generally use parameter for a variable named in the parenthesized list in a function definition,
 * and argument for the value used in a call of the function. (K&R pg25)
 **************************************************************************************/

    getchar();

    return 0;
}

/*power: raise base to n-th power; n>= 0 */

int
power(int base, int n)
{
    int i, p;

    p = 1;

    for (i = 1; i <= n; i++)
        p *= base;

    return p;
}