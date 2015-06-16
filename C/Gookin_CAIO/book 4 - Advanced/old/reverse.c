#include <stdio.h>

char *reverse(char *string);
//!intra un pointer si iese un pointer

int main()
{
    char input[64];
    char *backwards;

    printf("Enter here some text: ");
    gets(input);

    backwards = reverse(input);     //!reverse e functia!


    printf("\n\nCool!\n\tLet's see...\n\n");
    printf("This text, reversed, should be..\n\t\"%s\"" , backwards);
    puts("\n\n\n");

    return 0;
}

char *reverse (char *string)
{
    static char back[64];
    int len = 0;
    int x;

/*Get the string's lenght and set the last/first char*/
    while(*string)      //! ca sa afli marimea lui *string
     {
         len ++;
         string++;   //! ca sa te duci la urm portiune din memnorie
     }
     string--;      /*backup over NULL*/

/*Fill the array*/
    for(x=0; x<len; x++)
    {
        back[x] = *string;
        string--;
    }
    back[x] = '\0';      /*ending the NULL character*/
    return (back);
}
