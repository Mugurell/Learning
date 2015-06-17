#include <stdlib.h>

int inmultire (int x, int y);

int
main()
{
    int x, y;

    printf("Bo$$ , baga aici 2 numere ca sa le inmultesti %c\n" ,31);
    putchar('\t');
    scanf("%d", &x);
    putchar('\t');
    scanf("%d", &y);
    putchar('\n');
    printf("Rezultatul inmultirii este %d\n" , inmultire(x, y));
    getchar();

    return 0;
}
int inmultire(int x, int y)
{
   return x*y;
}
