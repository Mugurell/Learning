#include <stdio.h>

void underline (char *string);
int strlenght (char []); //!puteam pune si char *pointer

int main()
{
    int leght;
    char *point;
    char plm [] = "This Year's Starting Line-Up";
    point = &plm;

//    underline("This Year's Starting Line-Up");
    underline(point);

    leght=strlenght( point );  //! point e adresa string-ului de caractere
    printf("This%c string has %d characters", 24, leght);

    puts("\n\n");

    return 0;
}

void underline (char *string)
{
    puts(string);
    while(*string)      //! *string pt a citi caracterele
    {
        putchar('=');
        *string++;
    }
    putchar('\n');
}


int strlenght(char *pointer)
{
    int lenght=0;

 //   printf("%s" , pointer);

    while(*pointer)
    {
        lenght +=1;
        *pointer++;
    }

    return(lenght);
}
