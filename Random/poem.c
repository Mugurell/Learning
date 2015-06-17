#include <stdio.h>
#include <ctype.h>
#define SENTENCE 200

int main()
{
    char s[SENTENCE] = {"/0"};
    int x, d, l, sp;

    x=l=sp=d=0;

/*
    do
    {
        s[x] = "?";
        x++;
    } while(x<=SENTENCE);
*/

    printf("\t\tThe great letter counting program %c\n\n" , 2);
    printf("Type here the sentence of which you want the letters to be counted: %c\n" , 31);
    gets(s);


    for(x=0; x<SENTENCE; x++)
    {
        if(isalpha(s[x]))
            l++;
      if(isspace(s[x]))
            sp++;
        if(isdigit(s[x]))
            d++;
    }

/*Solutia lui Gorkin
    while(s[x])
    {
        if(isspace(s[x]))
            sp++;
        if(isalpha(s[x]))
            l++;
        x++;
    }
*/

    printf("\n\n\tHere comes the results....\n");
    printf("So....");
    printf("\nIn the previous sentence you had %d letters, %d digits and %d spaces!\n\n\n" , l, d, sp);
}
