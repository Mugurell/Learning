/*
** Write a function with this prototype: 
** int count_chars( char const *str, char const *chars );
** The function should look through the first argument and return the 
** number of characters that match characters in the second argument. 
*/

#include <stdio.h>
#include <unistd.h>

int count_chars(char const* str, char const* chars);

int main(void)
{
    char string1[100] = { "" };
    char string2[100] = { "" };
    int buffer;

    puts("Say something nice, please:");
    fgets(string1, 100, stdin);
    puts("Once more please (pref other saying):");
    fgets(string2, 100, stdin);
    puts("Now I'm gonna compare your 2 strings");
    puts("  and search for matching characters");

    for(int x = 0; x<3; x++) {
    	printf("\t...");
    	sleep(1);
    }
   
    printf("\n\n\t");

    buffer = count_chars(string1, string2);
    if (buffer == 0)
        puts("Sorry to dissapoint, but found no matches :-(\n");
    else
        printf("There are %d matches !!!\n\n", buffer);

    return 0;
}

int count_chars(char const* str, char const* chars)
{
    int x, y, count;
    x = y = count = 0;

    while(*str != '\0') {
        for(; *chars != '\0'; chars++) {
            if (str[x] == chars[y])
                count++;
        }
        str++;
    }
    return count;
}
