#include <stdio.h>

void low_level (void);
void stelute (void);

int main()
{
    int v, r, x;

    printf("Enter an integer value %c ", 16);
    scanf("%d" , &v);
    for(x=1; x<8; x++)
    {
        r = v << x;
        printf("%d << %d = %d\n" , v, x, r);
    }
    low_level();

    return 0;
}

void stelute (void)
{
    int x = 0;
    puts("");
    for(x = 0; x < 30 ; x++ )
        printf("*");
    puts("\n");
}

void low_level(void)
{
    stelute();

    int v , v2;
    int r = 10;
    int x = 0;

   // while("getchar() != '\n")
   //     continue;
/*! Asta e functie noua, diferita de int (main) <- unde a ramas restul
! Functia asta (low_level) pleaca pe curat,
! Nu are nici macar linie noua ramasa in buffer;
! Deci whileul de mai sus nu merge - pauzeaza toata functia ;-)
*/

    printf("Now enter a number to be multimplied by %d %c %c " , r, 1, 16);
    scanf("%d" , &v);
    v2 = v;
    v2 <<= r;
    puts("");
    printf("Nice pick, cool!\n\n");
    printf("So %d multiplied by %d equals....\n\t\t\t\t%d %c" , v, r, v2, 2);

    while("getchar() != '\n")
        continue;

}
