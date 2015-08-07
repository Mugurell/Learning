#include <stdio.h>

#define MAXLINE 100     /*maximum input line*/

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* PRINT LONGEST INPUT LINE*/

int
main()
{
    int len;                // current line lenght
    int max;                // maximum lenght seen so far
    char line[MAXLINE];     // current input linede
    char longest[MAXLINE];  // longest line saved here

    max = 0;

    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)            // there was a line
    	printf("The longest line is\n");
        printf("%s", longest);
        printf("\nThe lenght of it is %d", max);

    getchar();

    return 0;
}



/*GETLINE: READ A LINE INTO S, RETURN LENGHT*/
int
getline(char line[], int max)
{
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != '\n'; i++)
    {
        //( i 0 - 98 ca sa intre si '\0' - dupa ce se termina for loopul)
        line[i] = c;		// i++ din for loop imi incrementeaza pozitia in array
        if (c == '\n')
        {
            line[i] = c;	// imi pune si new line in array la ultima pozitie
            i++;			//mai incrementeaza odata i pt ca..(vezi mai jos)
        }
    }
    line[i] = '\0';			// dupa new line mai pune si null character
    return i;
}

/*COPY: COPY 'FROM' INTO 'TO'; ASSUME TO IS BIG ENOUGH*/
void
copy(char longest[], char line[])
{
    int i;

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        i++;

    /* echivalent cu
    ** for(i=0; longest[i] = line [i] != '\0')
    **              ;
    */
}