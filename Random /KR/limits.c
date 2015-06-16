#include <stdio.h>      // basic input - output
#include <time.h>       // necesar pt orice tine de time
#include <stdlib.h>     // necesar pentru rand
#include <ctype.h>      // necesar pt tolower and toupper
#include <string.h>     // necesar pt strlen

#define MAX_TRIES 5

void hangman (char cuvinte[][11]);      //will preserve the array's dimensions when passed.

int main()
{
    char response, cuvinte[3][11] = {"algocalmin", "marguerita", "gheorghe"};
    int var = 1;

    puts("\t Spanzuratoarea\n\n");

    srand((unsigned)time(NULL));

    do
    {
        printf("Wanna play Hangman? Y/N\n\t");
        //  fgets(&response, 1, stdin);
        response = toupper(getchar());
        fflush(stdin);

        switch (response)
        {
        case 'N':
        {
            printf("Okey, your loss\n");
            var = 0;
            break;
        }
        case 'Y':
        {
            hangman(cuvinte);
            break;                  //best practice sa pui brake mereu, chiar si la ulimul case():


        }
        default:
        {
            puts("Zii frate Y sau N\n\t");
            break;              //best practice sa pui brake mereu, chiar si la default
        }
        }


    }
    while (var);       // !var == var este 0
    // iar var e 1...

    getchar();

    return 0;
}

void hangman (char cuvinte[][11])
{
    int  i;             //un intreg de folosit in loopuri
    int cuvant_nr;      //un int pt numarul cuvantului ales din array-ul cuvinte[][11]
    int incercari = 0;  //cate litere a incercat deja
    char word[11];      //cuvantul ce va fi ghicit, max 11 chars, toate initializate mai jos cu '-'
    char litera;        //litera scrisa de ghicitor
    int try = 0;        //flag daca userul a nimerit >= 1 litera/nu

    puts("Now I'm gonna choose a very tough word for you to guess");
    cuvant_nr = rand() % 3;                     //numarul cuvantului din array
    char *chosen_word = cuvinte[cuvant_nr];     //pointer pt cuvantul ales
    int len = strlen(chosen_word);

    /*Initializam tot cuvantul cautat cu '-' pentru a ascunde literele*/
    for (i = 0; i < len; i++)
        word[i] = '-';
    word[i] = '\0';

    printf("The word is %s\n", word);
    while (incercari < MAX_TRIES)
    {
        printf("\tEnter your guess\n\t");
        litera = tolower(getchar());
        fflush(stdin);
        i = 0;
        try = 0;

        do
        {
            //  if (chosen_word == word)      //nu poti sa compari 2 stringuri cu '==' hint:strcmp

            /*Test pt a vedea daca litera introdusa de user se regaseste in cuvant*/
            if (litera == chosen_word[i])
            {
                word[i] = litera;
                try = 1;        //userul a ghicit cel putin o litera
            }
            i++;
        }
        while (chosen_word[i] != '\0');

        /*II dam rezultatul testului de mai sus*/
        if (try == 1)
        {
        	/*Userul a ghicit cuvantul -> early finnish (break)*/
            if (strcmp(word, chosen_word) == 0)
            {
            	puts("You guessed the word!");
            	puts("You're awesome!!!\n\n\t");
            	break;			//break te scoate dintr-un switch-case sau ORICE loop (for/while/do-while)
            }
            else
            {
                puts("Great!");
                printf("The word now is %s\n\t", word);
            }
        }
        else
        {
            puts("Wrong!");
            incercari++;
            if ((MAX_TRIES - incercari) > 0)
                printf("\tYou now have %d more tries\n", MAX_TRIES - incercari);
            else
                printf("You lost motherfucker!!!\n Muahahaha\n\n");
        }
    }
    //   printf("***Exit game***\n");



}