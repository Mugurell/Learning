/*
** Write a function called my_strnchr with this prototype: 
** char *my_strnchr( char const *str, int ch, int which );
** The function is similar to strchr except that the third argument specifies which 
** occurrence of the character is desired. For example, if the third argument is one, the 
** function behaves exactly like strchr. If the third argument is two, the function 
** returns a pointer to the second occurrence of ch in the string str. 
*/

#include <stdio.h>
#include <unistd.h>

char* my_strnchr(char const* str, int ch, int which);

int main(void)
{
    char string[100] = { "" };
    char litera;
    char* buffer;
    int nr, x = 0;

    puts("\nSay something nice:");
    fgets(string, 100, stdin);
    printf("Now what char should I search for? : ");
    litera = getchar();
    printf("In the event that are more %c's", litera);
    printf("\n\tto which one would you like me to point?: ");
    scanf("%d", &nr);
    puts("ok, let's get to it!");

    while (string[x] != '\0') {
        sleep(1);
        printf("\t%p is %c\n", &string[x], string[x]);
        x++;
    }

    buffer = my_strnchr(string, litera, nr);
    if (buffer == NULL) {
        puts("Unfortunately I wasn't able to find");
        printf("\tany %c's in your string :-(\n\n", litera);
    } else {
        puts("After extensive search in your string..");

        printf("\t#%d \"%c\" found !! :\n", nr, litera);
        printf("\t%p says %c\n\n", buffer, *buffer);
    }

    return 0;
}

char* my_strnchr(char const* str, int ch, int which)
{
    char* location = NULL;
    int nr = 0;

    while (*str != '\0') {
        if (*str == ch) {
            nr++;
            location = str;
        }
        str++;
    }

    if (nr > 0 && nr < which) {
    	puts("Unfortunately,");
        printf("\tThe last \"%c\" was at %p.\n", ch, location);
    }

    return location;
}