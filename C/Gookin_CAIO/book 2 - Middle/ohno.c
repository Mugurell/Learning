#include <stdio.h>

int main()
{
    int naughty = 0;

    loop:
        puts("Naughty, naughty");
        naughty++;
        if(naughty <10)
            goto loop;




    /*int naughty;

    for(naughty=0; naughty<10; naughty++);
    {
        puts("Naughty, naughty");
    }*/


    return 0;

}
