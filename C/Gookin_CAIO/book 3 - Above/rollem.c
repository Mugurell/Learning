#include <stdio.h>      //!standard io
#include <stdlib.h>     //!pentru if, for, etc
#include <time.h>       //!pentru srand si rand

int rolls(int);     //!functia rolls ce returneaza un int si mananca un int
int total;          //! variabila globala
                    //! (isi pastreaza/modifica valoarea in toate functiile)

int main()
{
    int many;

    srand((unsigned) time (NULL));

    puts("\t\tROLL ' EM !");
    putchar('\n');
    putchar('\n');

    printf("How many dice would you like to roll (1 to 12) ? %c ", 16);
    scanf("%d" , &many);

/*!Horia's gem!
Ia fiecare caracter din stdin pe rand
Cand e diferit de '\n' continue => funcita while de la inceput
Si tot asa, caracter cu caracter, pana citeste '\n' - linie noua
si atunci iese din nwhile loop
DAR! Mi-a citit linia noua => getchar are efect din prima!
*/
    while (getchar() != '\n')
        continue;

        if(many == 1)
    printf("\n\n\t..Rolling the dices only once %c" , 2);
        if(many != 1)
    printf("\n\n\t..Rolling the dices %d times %c" , many, 1);


    printf("\n\n\n\nHere they come....\n\n");

    rolls(many);

    printf("\n\n\tTotal = %d\n\n", total);

    getchar();

    return 0;
}

int rolls(many)
{
    int x, d1, d2, td1 = 0, td2 = 0;
    for(x=0; x<many; x++)
    {
        d1 = rand ()% 6+1;
        td1 += d1;
        printf("%4d", d1);
    }
    x=0;

    putchar('\n');
    putchar(' ');
    putchar('+');
    do
    {
        for(x=0; x<many; x++)
            printf("---+");
    }
    while(x<many);
    putchar('\n');
    putchar(' ');
    x=0;

    putchar('|');
    for(x=0; x<many; x++)
    {
        d2 = rand () % 6+1;
        td2 += d2;
        printf(" %d |" , d2);
    }
    x=0;

    printf("\n +");

    do
    {
        for(x=0; x<many; x++)
            printf("---+");
    }
    while(x<many);

    total = td1+td2;

    return(total);
}

