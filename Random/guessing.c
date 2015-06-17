#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 100

int main()
{
    int min = MIN, max = MAX;
    int me_guess = 0;
    int comp_guess = 0;
    char res;

    srand((unsigned)time(NULL));

    printf("First, I'll choose a no between %d and %d: ", MIN, MAX);
    scanf("%d", &me_guess);
    fflush(stdin);

    do
    {

        if(min == max)
        {
            printf("\n\n\t\tThat would mean your chosen number is %d !!!\n" , min);
            printf("\t\t****************************************\n");
            printf("\t\t\t****Damn, I'm good %c****\n", 1);
            printf("\t\t****************************************\n");

            goto tambalau;
        }


        printf("\n\nNow you guess, what number did i choose between %d and %d\n", min , max);
        comp_guess = rand() % (max - min);
        comp_guess += min;

        printf("\n\t\tI say, in my absolute knowledge, the number you chose is.. %d\n", comp_guess);


        if (me_guess == comp_guess)
        {
            printf("\t\t****************************************\n");
            printf("\t\t\t****Damn, I'm good %c****\n", 1);
            printf("\t\t****************************************\n");
            break;
        }

        printf("\t\tAm I close?\n\t\tEnter \"H\" if your chosen number is higher, or L if ... %c " , 16);

        res = getchar();
        while(getchar() != '\n')
            continue;


        switch (res)
        {
        case 'H':
        case 'h':
        {
            min = comp_guess + 1;
            break;
        }

        case 'L':
        case 'l':
        {
            max = comp_guess - 1;
            break;
        }
        default:
            puts("Naughty !");
            break;
        }

    }while (1);

    tambalau:

    return 0;
}
