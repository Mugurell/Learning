#include <stdio.h>

int main()
{
    char prompt[] = "Please enter your first name:";
    char prompt2[] = "Now, what is your last name?";
    char gratis[] = "Thanks!";
    char first[25];
    char last [20];

    printf(prompt);
    gets(first);
    printf(prompt2);
    scanf("%s" , &last);
    puts(gratis);
    printf("\nPleased to meet you, %s %s\a!" , first , last);
    return 0;
}
