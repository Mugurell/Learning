#include <stdio.h>
#include <string.h>
int main()
{
    char yours [25];
    char mine [] = "Henry";

    printf("What is your name? ");
    gets(yours);


//! strcmp compara 2 elemente (tine cont si de majuscule) si da 0 daca sunt identice
//!strcasecmp -=- doar ca nu tine cont de majuscule
    if (strcasecmp(mine, yours))
// se citeste daca 0/1 (fals/adevarat) => isi face functia/sare mai departe
// strcasecmp da 0 doar cand string-urile sunt identice
//    caz in care if-ul asta e 0 (fals) => sare peste el
//!
// strcasecmp da 1, deci if-ul are efect atunci cand string-urile sunt diferite
    printf("Interesting name, this... %s\n\n" , yours);

    else
         printf("We both have the same name!!!\a\n\t\t\tWhoaaa!!!\n\n");


    return 0;
}
