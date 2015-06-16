/* Write a program that reads from the standard input and computes the 
percentage of characters it finds in each of the following categories: 
    control characters 
    whitespace characters 
    digits 
    lower case letters 
    upper case letters 
    punctuation characters 
    non‐printable characters 
Use the character categories that are defined for the ctype.h functions.
*/

#include <stdio.h>      /* basic IO functions */
#include <ctype.h>      /* is***** functions */

void analysis(char *string);

int main(void)
{
    char string[100];

    puts("\nSay something nice!");
    fgets(string, 100, stdin);
    puts("\nNow get ready for an interesting analysis..");
    puts("\tSo, in the above string you had:");

    printf("***String 1***:\n\t%s", string);
    analysis(string);
    printf("***String 2***:\n\t%s", string);
    puts("DONE");

    return 0;
}

void analysis(char *string)
{
    puts("**I was here**");
    float chars, ctrl, space, digits, lower, upper, punct, non;
    chars = ctrl = space = digits = lower = upper = punct = non = 0;

    //pastram un pointer catre primul element, pentru ca dupa ce incepem sa incrementam "string" in primul loop, 
    //trebuie sa-l "resetam" pe string la primul element pentru a fi parcurs iarasi incepand cu elementul 0, in al 2lea loop;
    char *pointer_to_first = string;

    while (*string)
    {
        chars++;

        //trebuie sa incrementam poinerul ca sa treaca la urmatorul element
        string++;
    }

    //reseatam pointerul string sa pointeze din nou catre primul element
    string = pointer_to_first;

    while (*string) {
        if (iscntrl(*string))
            ctrl++;
        else if (isspace(*string))
            space++;
        else if (isdigit(*string))
            digits++;
        else if (islower(*string))
            lower++;
        else if (isupper(*string))
            upper++;
        else if (ispunct(*string))
            punct++;
        else if (!isprint(*string))
            non++;
        else
            printf("Mai era ceva bha!\n");

        //trebuie sa incrementam poinerul ca sa treaca la urmatorul element
        string++;
    }

    ctrl = (ctrl * 100) / chars;
    space = (space * 100) / chars;
    digits = (digits * 100) / chars;
    lower = (lower * 100) / chars;
    upper = (upper * 100) / chars;
    punct = (punct * 100) / chars;
    non = (non * 100) / chars;

    printf("control chars: %.2f%%,\n", ctrl);
    printf("whitespace chars: %.2f%%,\n", space);
    printf("digits: %.2f%%,\n", digits);
    printf("lower case letters: %.2f%%,\n", lower);
    printf("upper case letters: %.2f%%,\n", upper);
    printf("punctuantion chars: %.2f%%,\n", punct);
    printf("non_printable chars: %.2f%%,\n", non);
}
