#include <stdio.h>

int main()
{
    enum days {Monday = 100, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

    int x;

//!ca sa vezi valorile auto atribuite de enum lui days
    for(x=Monday; x<=Sunday; x++)
        printf("X = %d\n" , x);
    x=0;
    printf("\n\n\n");

//!Zilele saptamanii in ordine
   for(x=0; x<=6; x++)
       printf("%s\n" , x);
   x=0;

    return 0;
}
