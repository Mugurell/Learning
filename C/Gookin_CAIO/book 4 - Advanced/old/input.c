#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_1(void);

int main()
{
    char *input;
    int size;

/*Allocate "enough memory"*/
    input = (char *)malloc(4069);       //!4K input buffer
    if(input == (char*) NULL)
    {
        puts("Out of memory");
        return 0;
    }
//! Altfel inseamna ca a reusit sa-i aloce memoria.
//! Doar doua solutii posibile: reuseste sau returneaza NULL

    printf("Say something..: ");
    gets(input);

/*resize input buffer to save space*/
    size = strlen(input) +1;        //! +1 for NULL
    if(!realloc(input, size))
//! bolean : daca nu a reusit realloc
//! si realloc (la fel ca malloc) return NULL daca nu reuseste
//! din nou boolean: if(!x) = daca nu x ->{....}
    {
        puts("Unable to reallocate memory");
        return 0;
    }

    puts("Memory reallocation successful");
    printf("String is: %s\n\n", input);

//! Atentiune: FUNCTIA FREE ()
    free(input);
    puts("Memory has been released");
    printf("String now is %s", input);

    return 0;
}
