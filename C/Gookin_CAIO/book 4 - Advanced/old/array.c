#include <stdio.h>

void array_1(void);
void array_2(void);
void array_3(void);
void array_4(void);
void array_5(void);

void showarray_1(int array[]);
void showarray_2(int *array);
void showarray_3(int *array, int size);
void showarray_4(int *array, int size);
void showarray_5(int *array, int size);
void modArray_5(int *array, int size);

int main()
{
    array_5();

    puts("\n\n");
    return 0;
}

void array_1(void)
{
    int primes[] = {2,3,5,7,9,11,13};

    showarray_1(primes);
}

void showarray_1(int array[])
{
    int x;
    printf("The first 7 primes numbers are: ");
    for(x=0; x<7; x++)
        printf("%d, ", array[x]);
}



void array_2(void)
{
    int *primes []= {2,3,5,7,9,11,13};

    showarray_2(primes);
}

void showarray_2(int *array)
{
    int x;
    printf("The first 7 prime numbers are %c", 16);
    for(x=0; x<7; x++)
        printf(" %d," , *(array+x));
}



void array_3(void)
{
    int *primes[] = {2,3,5,7,9,11,13};

    showarray_3(primes, 6);
}

void showarray_3(int *array, int size)
{
    int x;

    printf("The first 7 prime numbers are : ");
    for(x=0; x<size; x++)
        printf(" %d,", *(array+x));
}




void array_4(void)
{
    short int *primes [] = {1,3,5,7,9,11,13};
    int size = sizeof(primes)/4;  //!rezultatul e 7
//! la primes se gaseste doar primul element din array !!!!!!
//! => tre sa folosesti primes
    showarray_4(primes, size);
}

void showarray_4(int *array, int size)
{
    int x;

    printf("The first 6 prime numbers are : ");
    for(x=0; x<size; x++)
        printf(" %d,", *(array+x));
}




void array_5(void)
{
    int *primes [] = {2,3,5,7,9,11,13};

    puts("Original Array:");
    showarray_5(primes, 6);
    modArray_5(primes, 6);
    puts("Modified Array:");
    showarray_5(primes, 6);
}

void showarray_5(int *array, int size)
{
    int x;

    for(x=0; x<size; x++)
        printf("Element %d: %d\n" , x+1, *(array+x));
    puts(" ");
}

void modArray_5(int *array, int size)
{
    int x;

    for(x=0; x<size; x++)
        *(array+x) *=2 ;     //!double the value
                            //!*(array+x) * 2, rezultat stocat in *(array+x)
                            //! *(array+x) = *(array+x)*2

//! fiecare element din array(din primes defapt) e inmultit cu 2
//! treaba e ca functia asta manipuleaza array-ul din alta functie
//!     - frumusetea pointerilor ;-)
}
