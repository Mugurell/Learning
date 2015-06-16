#include <stdio.h>
#include <ctype.h>

void request (void);

/*! char input poate fi definit ca variabila globala
pentru ca valoarea sa fie rw in functii diferite*/
//char input [64] = "";

int main()
{
    char ch;

    do
    {
        puts("\nMain Menu\n=========");
        printf("Press 1 to enter new request or 6 to quit: ");
        ch = toupper(getchar());
        fflush(stdin);
        switch(ch)
        {
        case '1':
            request();
            break;
        case 'Q':
            puts("Quiting now..");
            break;

        default:
            printf("Naughty Input ! %c\n\n\n" , 1);
        }
    }while (ch != 'Q');      //! oricum trece odata prin functia do ;-)
}

void request (void)
{

/*!sau poate fi definita ca variabila statica
pentru  a fi rw in functii diferite*/
//    statc char input [64] = "";
    static int input = 0;

    puts("\tNew Request!");
 //   printf("\tPrevious request was\"%s\"\n" , input)
    printf("\tPrevious request was \"%d\"\n" , input);
//! \" pui ca sa arate ghilimeaua ;-)
    printf("\tEnter new request: ");
    scanf("%d" , &input);
    fflush(stdin);
/*! whileul de mai jos nu merge pt ca folosim int si nu char*/
 //  while(getchar !='\n')
   //     continue;

    puts("\tThank you!\n\n");
}
