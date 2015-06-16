#include <stdio.h>

int main()
{
    int nota;

    puts("Ce nota ai luat la ultimul test?");
    scanf("%d" , &nota);

if(nota>0 && nota<=10)
    printf("Asadar ai luat %d, o nota %s. Bravo!\n\n\r", nota, (nota>+8) ? "buna" : "rea");
else
    puts("O nota de la 1 la 10 ba baiatule!");

    return 0;
}
