#include <stdio.h>

void name_1 (void);
void name_2 (void);

int main()
{
    name_2();

    return 0;
}

void name_1(void)
{
    char name[30];
    char *n = name;
    int x = 0;

    printf("Please enter your name here %c ", 16);
    gets(name);
 //   while(getchar() != '\n')
   //     continue;

    printf("\nSo your name is ");
    while(putchar(*n++))
        ;
    putchar('?');
    putchar(' ');
    getchar();
    puts("\nOkey...");

}

void name_2(void)
{
    char name[30];
    char *n = name;
    int x = 0;

    printf("Please enter your name here %c ", 16);
    gets(name);
 //   while(getchar() != '\n')
   //     continue;

    printf("\nSo your name is ");
    puts(n);
    putchar('?');
    putchar(' ');
    getchar();
    puts("\nOkey...");
}
