#include <stdio.h>

int main()
{
    double ln;

    ln = 0;
/*
    while(getchar() != '\n'){
        ln++;
    }
*/
    for(ln=0; getchar() != '\n'; ln++)
    ;


    printf("%.0f\n", ln);

    return 0;

}
