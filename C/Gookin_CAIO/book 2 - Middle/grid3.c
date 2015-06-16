#include <stdio.h>

int main()
{
    int x;
    char a;

    for(x=1;x<11;x++)
    {
        for(a='A';a<'A'+10;a++)
            printf("%d%c%\t" , x, a);
    }
    return 0;
}
