#include <stdio.h>

int main()
{
    int v, r;

    printf("Enter an integer value %c ", 16);

    scanf("%d" , &v);
    while(getchar() != '\n')
        continue;

    r = v >> 2;  //!shift bits one notch right
                    //!result = value >> steps;

    printf("\n\t%d cut in quarters equals...\n\t\t\t\t..%d" , v, r);
    getchar();

    exit (7696);
}
