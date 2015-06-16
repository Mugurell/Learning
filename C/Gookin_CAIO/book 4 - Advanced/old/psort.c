#include <stdio.h>

#define SIZE 8

void psort_1(void);
void psort_2(void);

char *names[] =
{
    "Mickey",
    "Minnie",
    "Donald",
    "Daisy",
    "Goofy",
    "Chip",
    "Dale",
    "Pluto"
};

char *temp;
int a,b,x;

int main()
{

    psort_2();

    return 0;
}

void psort_1(void)
{


    for(a=0; a<SIZE-1; a++)
        for(b=a+1; b<SIZE; b++)
        {
            if(*names[a] > *names[b])
            {
                temp = names[a];
                names[a] = names[b];
                names[b] = temp;
            }
        }

    for(x=0; x<SIZE; x++)
        printf("%s\n" , names[x]);
}

void psort_2(void)
{
    for(a=0; a<SIZE-1; a++)
        for(b=a+1; b<SIZE; b++)
    {
        x=0;
        while(*(*(names+a)+x))
        {
            if(*(*(names+a)+x) > *(*(names+b)+x))
            {
                temp = *(names+a);
                *(names+a) = *(names+b);
                *(names+b) = temp;
            }
            else if (*(*(names+a)+x) < *(*(names+b)+x))
                break;
            else
                x++;

        }
    }

    for(x=0; x<SIZE; x++)
        printf("%s\n" , *(names+x));
}
