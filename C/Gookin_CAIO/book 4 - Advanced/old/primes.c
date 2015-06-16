#include <stdio.h>

void primes_1(void);
void primes_2(void);


int main()
{
    primes_2();

    return 0;
}

void primes_1(void)
{
    int primes [] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29};
    int x;
    int *p;

    printf("The first 10 primes numbers are %c\n" , 31);

    p = primes;     //! cand ai array nu e oblig sa mai pus ampersand
                    //! ampersand e oblig pentru alte variabile
                    //! sau pentru un element din array

    for(x=0; x<10; x++)
    {
        printf("\t\t\t\t%d\n" , *p++);
                /*! cand plusezi un pointer nu aduni +1
                  * ci sari la urmatoarea portiune din memorie
                  * in cazul asta sari 2 biti - pana la urmatorul element din array
                */
    }

 //   printf("The fifth prime number is %d\n" , primes[4]);

    p=primes;   //!fara reinitilizare => buffer overrun !

    printf("The fifth prime number is %d" , *(p+4));
    printf("\n\t and the seventh prime number is %d" , *(p+6));
    puts("\n\n");
    getchar();

}

void primes_2(void)
{
    int primes [] = {2,3,5,7,11,13,17,19,23,29};
    int *p;
    int x = 0;

    p = primes;

    while(x<10)
    {
    printf("\t%d\n" , *p++);
    x++;
    }
}
