#include <stdio.h>

#define SIZE 10

int main(void)
{
    int x[SIZE] = {
        1, 2, 3, 4, 5, 6, 7, 8,
    };
    /*If start to initialize an int array but don't finish initializing*/
    /* All the left positions (SIZE - 8) are auto-initialized to 0*/
    int y[SIZE];

    /*
	** To eliminate copying the pointer variables into adress registers
	** before the indirection, we store them on registers from start
	*/
    register int* ptrx, *ptry;

    for (int w = 0; w < SIZE; w++)
        printf("x-%d\t\ty-%d\n", x[w], y[w]);

    /*
	** ptrx < &x[SIZE] is more efficient than
	** ex: for( i = 0, p1 = x, p2 = y; i < SIZE; i++ )
	**			*p1++ = *p2++;
	** because it does not do substractions.
	** Furthermore, the expression &x[SIZE] can be evaluated
	** at compile time, because SIZE is a literal constant.
	*/
    for (ptrx = x, ptry = y; ptrx < &x[SIZE]; *ptry++ = *ptrx++)
        ;

    puts("\n\n");
    for (int w = 0; w < SIZE; w++)
        printf("x-%d\t\ty-%d\n", x[w], y[w]);

    return 0;
}