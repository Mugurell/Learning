#include <stdio.h>
#include <string.h>

int main()
{
    char command [64];
    char response[] = "You think I know how to ";
    char new[128];

    while(strcasecmp(command , "quit"))
//!Atat timp cat command e diferit de quit.
//!strcmp poate sa dea 0/-1/1
//!Cand sunt la fel strcasecmp iti da 0 => while e fals si se opreste
    {
        printf("C:\\>");
        gets (command);

        strcpy(new, response);
//!response copiezi in new
//! You think I know how to....
        strcat(new, command);
//!                         ...call the police...
        strcat(new , "?");
//!                                           ...?
        printf("%s\n" , new);
        printf("\nToata propozitia de mai sus are #%d caractere\n\n" , strlen(new));
    }
//!Cand scrii quit, strcasecmp e 0, while e fals, se opreste, sare la puts de mai jos
    puts("Well, maybe I do...");
//!Si gata, a trecut prin tot programul..
    return 0;
}
