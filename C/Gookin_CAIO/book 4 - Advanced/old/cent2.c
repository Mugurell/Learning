#include <stdio.h>

void cent_1(void);
void cent_2(void);
void cent_3(void);

int x = 0, cent[8];
int *c = cent;


int main()
{
    cent_1();

    return 0;
}

void cent_1(void)
{
    for(x=0; x<8; x++)
    {
        *c = (x+1) * 100;
        printf("%i x 100 = %d\n", x+1, *c);
    }
}
