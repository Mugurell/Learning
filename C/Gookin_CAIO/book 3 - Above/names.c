#include <stdio.h>

int main()
{

//!4 randuri cu 3 strings cu 9 caractere (+NULL la sfarsit)
    char names[4][3][10] = {
            "Bob",   "Bill", "Bret",
            "Dan",   "Dave", "Don",
            "George", "Harry", "John",
            "Mike",  "Steve", "Vern"
        };
    int a, b;

for(b=0; b<3; b++)
    for(a=0; a<4; a++)
        printf("%s\n" , names[a][b]);

    return 0;
    }
