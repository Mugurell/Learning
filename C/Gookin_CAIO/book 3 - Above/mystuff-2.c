#include <stdio.h>
#include <ctype.h>

typedef struct stuff
{
    char letter;
    int number;
}junk;      //!junk e aliasul lui stuff

void showstuff(junk the);   //!the e variabila pt junk

int main()
{
    char input [10];
    junk my;  //!am declarat variabila my pentru stuct stuff

    puts("\t\tYour Own stuff\n\n");

    printf("Enter your favourite letter %c " , 16);
    my.letter=toupper(getchar());
//  scanf("%c" , my.letter);
//    my.letter = toupper(my.letter);

    printf("Enter your favourite number %c " , 16);
    scanf("%d" , &my.number);

    while(getchar()!= '\n')
        continue;

    showstuff (my);
    getchar();

    return 0;
}

void showstuff (junk the)
{
    puts("\n\n\t..So...\n");
    printf("Your favourite letter is %c" , the.letter);
    printf("\n\tand your favourite number is %d" , the.number);
}
