#include <stdio.h>

void snow_1(void);
void snow_2(void);
void snow_3(void);
void snow_4(void);

    const char *seven[] = {
        "bashful",
        "doc",
        "dopey",
        "grumpy",
        "happy",
        "sneezy",
        "sleepy"
        };

//! seven e un array de pointeri
//!    (pointers to pointers)

    int x, c;

int main()
{
    snow_4();

    return 0;
}

void snow_1(void)
{
    for(x=0; x<7; x++)
    {
        printf("%s\n" , *(seven+x));   //!-string-ul de la respectiva adresa
        printf("%d\n" , *(seven+x));    //!- adresa din memorie  - numara cu atentie!!!
        printf("%d\n\n" , sizeof(seven+x));   //!-spatiul ocupat - in byti
    }
}

void snow_2()
{
    for(x=0; x<7; x++)
    {
        for(c=0; c<3; c++)
            printf("%c" , seven[x][c]);
        putchar('\n');
    }

}

void snow_3(void)
{
   for(x=0; x<7; x++)
    {
        for(c=0; c<3; c++)
            printf("%c" , *(*(seven+x)+c));

/*!
Honestly, I can’t figure out what this beast is. This thing:
                    **(array+x)
is a shortcut reference to the first character of the string x in an array. And,
you may see the ** notation used when fetching values from an array of integer
pointers. But, with strings, the proper notation is
                    *(*(array+x)+c)
*/

        putchar('\n');
    }
}

void snow_4(void)
{
    for(x=0; x<7; x++)
    {
        c=0;
        while(*(*(seven+x)+c))
        {
            putchar(*(*(seven+x)+c));
            c++;
        }
        putchar('\n');
    }
}
