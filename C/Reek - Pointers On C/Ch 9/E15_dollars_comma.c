/*
**  The standard I/O library does not provide a mechanism for putting 
** commas in large integers when they are printed. For this exercise you
** will write a program that provides this capability for dollar amounts.
** The function will convert a string of digits (representing an amount
** in pennies) to dollars.
*/

#include <stdio.h>
#include <string.h>

void commas(char* dollars, char *pennies);

int main(void)
{
    char dollars[100] = { "" };
    char pennies[100] = { "" };

    puts("Enter a sum in pennies (with 1 decimal)");
    printf("without any commas or dots: ");
    fgets(pennies, 99, stdin);

    commas(dollars, pennies);
    puts("K. That sum, nicely arranged is");
    printf("\n%s\n\n", dollars);

    return 0;
}

void commas(char* dollars, char * pennies)
{

    /*
	** 1st: get rid of the newline read by fgets
	** strlen does not count  the nul !!!!!
	*/
    int len = strlen(pennies);
    pennies[len - 1] = '\0';
    *dollars++ = '$';
    /* 
	** Now the pennies array has len characters.
	** You need to put a dot after 2 chars
	** and a comma after each 3 more chars
	*/

    /*
	** If digit string is long enough, copy the digits that will
	** be on the left of the decimal point, putting in commas
	** where appropriate. If the string is shorter than 3
	** digits, force a '0' into dollars ahead of the '.' .
	*/
    if (len >= 3) {
        int i;

        for (i = len - 2; i > 0;) {
            *dollars++ = *pennies++;
            if (--i > 0 && i % 3 == 0)
                *dollars++ = ',';
        }
    } else
        *dollars++ = '0';

    /*
    ** Store the decimal point, and then store the remaining
    ** digits from 'pennies'. If 'pennies' had fewer than two digits,
    ** force in '0's instead. Then nul terminate dollars.
    */
    *dollars++ = '.';
    *dollars++ = len < 2 ? '0' : *pennies++;
    *dollars++ = len < 1 ? '0' : *pennies;
    *dollars = 0;
 }