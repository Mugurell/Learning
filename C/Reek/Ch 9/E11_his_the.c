/*
** Write a program that scans the standard input and counts the number
** of times the word ʺtheʺ appears.
** The comparison should be case independent, so ʹTheʺ and ʺTHEʺ donʹt
** count. You may assume that words will be separated from each other
** by one or more white‐space characters and that the input lines will
** be less than 100 characters in length.
** The count should be written to the standard output.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char const whitespace[] = "\n\t\r\f\v";

int main(void)
{
    char buffer[101] = { "" };
    int count = 0;

    /*
	** Read lines until EOF/ '~' is found.
	*/
    while (gets(buffer)) {
    	char *word;

    	/* 
    	** Extract words from the buffer one by one
    	** until there are no more.
    	*/
    	for(word = strtok(buffer, whitespace);
    		word != '~';
    		word = strtok(NULL, whitespace)) {
    			if(strcmp(word, "the") == 0)
    				count += 1;
    	}
    }
    printf("%d\n", count);

    return EXIT_SUCCESS;
}

/*
int the_search(char const *string);

int main(void)
{
    char string[101] = { "" };
    int buffer;

    puts("Say something nice:");
    fgets(string, 100, stdin);
    puts("Now I'm gonna scan how many times you've said \"the\".");
    for (int x = 0; x < 3; x++) {
        printf("\t...");
        sleep(1);
    }

    buffer = the_search(string);
    if (buffer == 0)
        puts("Nope, not even a single \"the\"!\n");
    else
        printf("You've got \"the\" %d times!\n", buffer);

    return 0;
}

int the_search(char const *string)
{
    char const whitespace[] = "\n\r\f\t\v";
    int count;
    char* word;

    while (*string != '\0') {
        for (word = strtok(*string, whitespace); word != NULL;
             word = strtok(NULL, whitespace)) {
            if (strcmp(word, "the") == 0)
                count += 1;
        }
        string++;
    }
    return count;
}
*/