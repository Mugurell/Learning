#include <stdio.h>

int main()
{
    char string;

    printf("Recensamanat: Partidul preferat:\n\n\n");
    printf("Deci, \"cu ce partid tii\"? : ");
    scanf("%c" , &string);

    printf("Ai zis %c\n", string);

    switch(string)
    {
    case('S'):
    case('s'):
    {
        puts("Deci tii cu PSD Comunistule!!!");
        break;
    }
    case ('D'):
    case ('d'):
    {
        puts("PDL huh Basistule!!!");
        break;
        default:
            puts("..Okey..");
        }
    }
    return 0;
}

