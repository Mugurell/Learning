#include <stdio.h>
#include <ctype.h>

int main()
{
    char adress[200];
    int x, space, digit, alpha;
    x=space=digit=alpha=0;

    printf("Please enter here you adress: %c\n", 31);
    gets(adress);

    while(adress[x])
    {
        if(isspace(adress[x]))
            space++;
        else if(isdigit(adress[x]))
            digit++;
        else if(isalpha(adress[x]))
            alpha++;
        x++;
    }

    printf("\n\nSo, just as a funny fact..,\n\tIn your adress you have %d letters, %d numbers and %d spaces\n\n", alpha, digit, space);
    return 0;
}
