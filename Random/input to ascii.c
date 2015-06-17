#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, a;
    for (x = 0; x <127; x++)
    {
        for (a = 0; a <127; a++)
        {
            printf("%3d%c\t" , x, a);
            x++;
        }
    }
    return 0;
}
