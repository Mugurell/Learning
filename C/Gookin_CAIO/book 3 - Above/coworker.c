#include <stdio.h>

int main()
{
    float iq [] = {90.365 , 94.365};
    int coleg;

    puts("IQ results...\n\n");
    for(coleg=0; coleg<2; coleg++)
    printf("Colegul # %d - %f.\n" , coleg , iq [coleg]);
    return 0;
}
