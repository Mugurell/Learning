#include <stdio.h>

int main()
{
    int x = 1;
    char a;

    while (x<10)
    {
        a='A';
        while(a<'J')
        {
            printf("%d%c\t" , x , a);
            a++;
            if (x==5 && a=='F') goto sfarsit;
        }

        putchar('\n');
        x++;

    }
    sfarsit:
    return 0;
}
