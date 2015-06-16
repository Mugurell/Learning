#include <stdio.h>

void peasoup(int *green);

int main()
{
    int turn=13;
/*    int *head;

    head = &turn;
//! Initializarea pointerului poate fi facuta fie inainte fie dupa ce turn a fost inializat
//! Nu conteaza!

    peasoup(*head);
*/
    peasoup(&turn);  //! - adresa din memorie a variabile int turn

    printf("Oh, no, it's %d!\n", turn);

    return 0;
}

void peasoup (int *green)
{
    while((*green)--)
        puts("Bleah!");

    *green = 13*51+3;
}

