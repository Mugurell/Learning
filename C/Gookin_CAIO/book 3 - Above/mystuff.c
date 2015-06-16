#include <stdio.h>
#include <ctype.h>

    struct stuff
    {
        char letter;
        int number;
    }my, his, her;   //!variabila poate fi definita "on the fly" la sf parantezei...
           //!sau separat asaa cum e mai jos

  //!  struct stuff my;    //stuff e structura, my e variabila
                            //! poti sa adaugi si alte variabile gen yours, his etc

    void showstuff(struct stuff the, char);
//! e declarata functia showstuff care mananca o structura stuff cu variabila the + si un caracter
//! a introdus o noua variabila - the

int main()
{
    char input [10];

    /*Here is his stuff*/
        his.letter = 'Y';
        his.number = 199;

    /*Here is her stuff*/
        her.letter = 'A';
        her.number = 21;


    puts("\t\tYour own stuff\n\n");

    printf("Enter your favourite letter %c " , 16);
    my.letter = getchar();

    printf("Enter your favourite number %c " , 16);
    scanf("%d" , &my.number);

    showstuff(my, 2);
//! valoarea lui my/him/her e trimisa ca argument functiei
//! nu conteaza cum se numeste conteaza valoarea
    showstuff(his, 1);
    showstuff(her, 3);



 //   printf("\n\nYour favourite letter is %c\n" , toupper(my.letter));
   // printf("\t..and your favourite number is %d %c\n" , my.number, 2);
    printf("\nHis favourite letter is %c\n" , tolower(his.letter));
    printf("\t..and his favourite number is %d %c\n" , his.number , 1);
    printf("\nHer favourite letter is %c\n" , toupper(her.letter));
    printf("\t..and her favourite number is %d %c\n\n\n\n" , her.number , 3);

    return 0;
}


void showstuff (struct stuff the, char c)
{
    printf("Your favourite letter is %c\n\t" , the.letter);
    printf("Your favourite number is %d%c\n\n" , the.number, c);
}
