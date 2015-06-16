#include <stdio.h>

int main(void)
{
    char array[10] = { 'H', 'e', 'l', 'l', 'o' };
    /**** OR****
    char array[10] = {"Hello"}
    ** produces the same exact result **/

    printf("Sizeof char array[10] = { \"Hello\"} is %lu", sizeof(array));
    printf("\n%s###\n", array);
    printf("So although it reserved space for 10 chars but only 6 were occupied, the ones left are not initialized by default like in the case of ints but they are simply skipped");

    return 0;
}