#include <stdio.h>
#include <string.h> //!pt strcpy
#include <stdlib.h>


void howdy_1(void);
void howdy_2(void);

int main()
{

    howdy_2();

    return 0;
}

void howdy_1(void)
{
    char *string;

    string = (char *)malloc(80);
//! malloc tre sa gaseasca spatiu pentru 80 caractere

    if(string == (char *) NULL)
    {
        puts("Not enough memory");
    }

    strcpy(string, "Howdy! Howdy! Hi!");
    printf("%s\n", string);

}

void howdy_2(void)
{
    char input[100];
    char *dupe;
    int lenght;


    printf("Say something: ");
    gets(input);
    lenght = strlen(input)+1;
//! inca un caracter in care sa fie NULL
//! strlen nu numara si NULL character

//!    dupe = (char *)malloc(lenght*sizeof(char));   lenght*1....
    dupe = (char *)malloc(lenght);

    if (dupe ==(char *)NULL)
//! daca dupe == NULL - citit ca char (char * e typecast
//! pentru ca malloc returneaza fie adresa fie NULL
    {
        puts("Not enoght memory");
        return 0;
    }

    strcpy(dupe, &input);

    printf("\nOriginal string is: %s\n", input);
    printf("Duplicate string would be: %s\n\n" , dupe);

}
