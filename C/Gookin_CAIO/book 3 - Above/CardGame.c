#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define DRAW 5

void showcard(int card);

int main()
{
    int x, c;

    srand((unsigned)time(NULL));
    for(x=0; x<CARDS; x++)
    {
        c = rand() % CARDS;
        showcard(c);
    }
    return 0;
}

/*Take values 0 through 51 n(cards in a deck) corresponding card name*/

void showcard(int card)
{
    char *suit[4] = {"Spades" , "Hearts" , "Clubs" , "Diamonds"};

    switch(card%13)
    {
    case 0:
        printf("%2s" , "A");
        break;
    case 10:
        printf("%2s" , "J");
        break;
    case 11:
        printf("%2s" , "Q");
        break;
    case 12:
        printf("%2s" , "K");
        break;
    default:
        printf("%2d" , card%13+1);
        printf("%2d" , card%13+1);
    }
    printf(" of %s\n" , suit[card/13]);
}

