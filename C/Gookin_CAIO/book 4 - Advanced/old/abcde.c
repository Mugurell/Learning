#include <stdio.h>


void abcde_1(void);
void abcde_2(void);
void pointers_crap(void);

int a,b,c,d,e,x;
int *var[5];    //! declares an ARRAY OF 5 POINTERS !!!!



int main()
{
    pointers_crap();

    return 0;
}

void abcde_1(void)
{
    a = 1;
    b = a*2;
    c = b*2;
    d = c*2;
    e = d*2;

    var[0] = &a;
    var[1] = &b;
    var[2] = &c;
    var[3] = &d;
    var[4] = &e;

    for(x=0; x<5; x++)
        printf("Variable %c = %d\n" , 'A'+x, *var[x]);
}

void pointers_crap(void)
{
    char smth [][20] = {"Type something : " , "C:\\" , "."};
    const char *pointer[] = {"Type something : " , "C:\\" , "."};
    char *sm = smth;

    for(x=0; x<3; x++)
    {
        printf("%s\n", *(pointer+x));
    }

}
