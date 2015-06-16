#include <stdio.h>
#include <stdlib.h>     //mecesar pt exit
#include <string.h>     //necesar pt strlen
#include <math.h>       //necesar pt fabs


#define CENT_PER_INCH 2.54

int main ()
{
    union measure
    {
        float centimeters;
        int inch;
    } you, paul;
    //! centimeters sau inch sunt defapt aceeasi variabila - aceeasi valoare!
    //! care se numeste centimeters si este de tipul float
    //! sau se numeste inch si este de tipul int
    //!! 2 moduri de a ne referi/de a privi aceeasi valoare - float/int
    //!! cu 2 nume diferite

    //    union measure you, paul;

    paul.inch = 70;
    float diff;
    char title[] = "How do you stand when compare with Paul";
    int title_len;
    int x = 0;


    printf("\t%s\n\t" , title);
    title_len = strlen(title);
    for (x = 0; x < title_len; x++)
        printf("*");

    puts("\n");

    printf("Paul is %d inches tall.\n" , paul.inch);
    printf("How tall are you in inches? %c " , 16);
    scanf("%d" , & you.inch);

    you.centimeters = CENT_PER_INCH * (float)you.inch;
    paul.centimeters = CENT_PER_INCH * (float)paul.inch;
    diff = paul.centimeters - you.centimeters;
    diff = fabs(diff);      //returns the absolute value as a float 

    printf("\n\nSo...\n\tYou are %.1f centimeters tall" , you.centimeters);
  //  printf("\n After being %d inches ****", you.inch);        //returneaza junk pentru ca un union lucreaza doar cu un tip de valoare anytime
    printf("\n\tAnd Paul, being %.1f centimeters tall,\n\t\tis", paul.centimeters);
    if (paul.centimeters > you.centimeters)
        printf(" %.2f centimeters taller than you! %c" , diff, 2);
    else if (paul.centimeters < you.centimeters)
        printf(" %.2f centimeters shorter than you! %c" , diff, 1);
    else
        printf(" the same height as you!!!\n\t\tW O W !!!");

    puts("\n\n");

 //    fflush(stdin);       - NOT RECOMMENDED <-> undefined behaviour
    
    while(getchar() != '~')
        continue;

    getchar();

    exit(762323145);
}
