/*!
 * ✦ Without the asterisk, the pointer is a memory address.
 * ✦ With the asterisk, the pointer represents what lives at that address.
*/


#include <stdio.h>
#include <string.h>

#define SIZE 10

void sorter_1(void);

int main()
{
    sorter_1();

    return 0;
}

void sorter_1(void)
{
    char input[SIZE][64];
    char *isort[SIZE];
    char *temp;
    int x, a, b;


/*Get the SIZE number of strings*/
    printf("Enter %d types of fruit:\n", SIZE);

    for(x=0; x<SIZE; x++)
    {
        printf("\t\t#%d: ", x+1);
        gets(input[x]);
        isort[x] = input[x];    //!bagi input[x] la adresa isort[x]
    }

/*Sort the array using pointers*/
    for(a=0; a<SIZE-1; a++)
        for(b=a+1; b<SIZE; b++)
            if(strcasecmp(isort[a],isort[b]) > 0)

/*!
* strcasecmp compara 2 stringuri indiferent de cum literele sunt mari/mici
* rezultatul e 0 - cand stringurile sunt identice
*              1 - cand 1ul string e mai mare ca al 2lea
*             -1 - cand al 2lea string e mai mare
*/

            {
                temp = isort[a];
                isort[a] = isort[b];
                isort[b] = temp;
            }

/*Printf the results*/
    printf("\n\nSorted list:\tOriginal list:\n");

    for(x=0; x<SIZE; x++)
        printf("%12s\t%12s\n" , isort[x], input[x]);

}

void sorter_2(void)
{
    int input[SIZE];
    int *isort[SIZE];
    int *temp;
    int a,b,x;

    printf("Enter here your chosen numbers to be sorted %c \n", 16);
    for(x=0; x<SIZE; x++)
    {   printf("\t#%d: ", x+1);
        scanf("%d" , &input[x]);
        isort[x] = &input[x];       //! get adress, not value
    }

    for(a=0; a<SIZE-1; a++)
        for(b=a+1; b<SIZE; b++)
    {
        if(*isort[a]>*isort[b])       //! values
        {
            temp = isort[a];
            isort[a] = isort[b];
            isort[b] = temp;
        }
    }

    puts("\n\nOriginal\tSorted");
    puts("Numbers\t\tNumbers\n");
    for(x=0; x<SIZE; x++)
        printf("%-3d\t\t%-3d\n", input[x] , *isort[x]);

}


