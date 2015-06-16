#include <stdio.h>

void prompts_1(void);
void prompts_2(void);

int main()
{
    prompts_2();

    return 0;
}

void prompts_1(void)
{
    int x;
    char prompts [3][16] =
    {
        "Type something:" ,
        "C:\>",
        "."
    };

     for(x=0; x<3; x++)
    {
        puts(prompts[x]);

    }
}



void prompts_2(void)
{
    int x;
    char *prompts[] = {"Type something", "C:\>", "."};

 //   while(puts(*prompts++))
   //     ;
    for(x=0; x<3; x++)
    {
        puts(prompts[x]);

    }
}

