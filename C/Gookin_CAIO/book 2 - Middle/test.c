#include <stdio.h>

int main()
{
    int mult;

    printf("Cat de mult vrei sa reusesti pe o scara de la 1 la 10?: ");
    scanf("%d" , & mult);
    printf("%s" , (mult>7) ? "\n\nBine.\n\tDa-i bataie atunci!\n\n\a" : "\n\n:-| Esti varza!!\n\n");

    return 0;
}
