#include <stdio.h>

void cent_1(void);  //! increments the memory location before the *c value is fetched
void cent_2(void);  //! how to select a n individual element of the array using pointers
void cent_3(void);  //! 1+2+ increments the memory adresses (comparison)

int cent [8];
int x;
int *c = cent;


int main()
{
    cent_1();

    getchar();
    
    return 0;
}

void cent_1()
{
    for(x=0; x<8; x++)
    {
        *c = (x+1) * 100;
        printf("cent[%d] = %d\n" , x, ++*c);


        //! in *c++ - ++ has precedence over the *
        //! so it increments the memory location c
        //! before the *operator fetches a value
    }
}

void cent_2()
{
    for(x=0; x<8; x++)
    {
        *(c+x) = (x+1) * 100;
        printf("array[%d] = %d\n" , x, *(c+x));

    }
}

void cent_3()
{
    for(x=0; x<8; x++)
    {
        *(c+x) = (x+1) * 100;
        printf("cent[%d] = %d\t%d\t%i\t\n", x, ++*c, *(c+x), *c+x);
                    //! *c+x imi numara peste ++*c, d=asta sare din 2 in 2
                    //! altfel era din unu in unu (x++)
    }
}
