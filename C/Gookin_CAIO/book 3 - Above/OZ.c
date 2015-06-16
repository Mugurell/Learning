#include <stdio.h>
#include <string.h>
#define LINE_LENGHT 40

int main()
{
/*
        char actor[] = "Judy Garland";
        int age = 17;
        char role[] = "Dorothy";

        char actor2[] = "Ray Bolger";
        int age2 = 35;
        char role2[] = "Scarecrow";

        char actor3[] = "Bert Lahr";
        int age3 = 44;
        char role3[] = "Cowardly Lion";

        char actor4 [] = "Jack Haley";
        int age4 = 40;
        char role4 [] = "Tin Woodsman";

        int line;

        puts("\tWIzard of Oz Database!\n\n");

//draw the table heading
        printf("%-15s\t%3s\t%-15s\n" , "Actor" , "Age" , "Role");
        for(line = 0; line<LINE_LENGHT; line++) putchar ('-');
        putchar('\n');

//display the data
        printf("%-15s\t%3d\t%-15s\n" , actor, age, role);
        printf("%-15s\t%3d\t%-15s\n" , actor2, age2, role2);
        printf("%-15s\t%3d\t%-15s\n" , actor3, age3, role3);
        printf("%-15s\t%3d\t%-15s\n" , actor4, age4, role4);
*/

/*
    char actor [6][18]=
    {
        "Judy Garland",     //asta are 12 + NUL = 13 caractere
        "Ray Bolger" ,
        "Bert Lahr" ,
        "Jack Haley" ,
        "Margaret Hamilton" ,       //asta are 17 + NUL = 18 caractere
        "Frank Morgan"
    };

    int age [6] = {17 , 35 , 44 , 40 , 37 , 49};

    char role [6][16] =
    {
        "Dorothy" ,
        "Scarecrow" ,
        "Cowardly Lion" ,   //asta are 15 + NUL = 16 caractere
        "Tin Woodsman" ,
        "Wicked Witch" ,
        "The Wizard"
    };

    int line, x;

    puts("\t\tWizard of Oz Database\n\n");

//draw the table heading
    printf("%-15s\t%6s\t%-15s\n" , "Actor" , "Age" , "Role");
    for(line=0; line<LINE_LENGHT; line++) putchar('-');
    putchar('\n');

//display the data
    for(x=0; x<6; x++)
        printf("%-18s%3d\t%-15s\n" , actor[x], age[x] , role[x]);

*/


/*
    struct oz {
        char actor[18];
        int age;
        char role[16];
            }cast[6];     //!cast e variabila !!!

    int line, x;

    strcpy(cast[0].actor , "Judy Garland");
    cast[0].age = 17;
    strcpy(cast[0].role , "Dorothy");

    strcpy(cast[1].actor , "Ray Bolger");
    cast[1].age = 35;
    strcpy(cast[1].role , "Scarecrow");

    strcpy(cast[2].actor , "Bert Lahr");
    cast[2].age = 44;
    strcpy(cast[2].role , "Cowardly Lion");

    strcpy(cast[3].actor , "Jack Haley");
    cast[3].age = 40;
    strcpy(cast[3].role , "Tin Woodsman");

    strcpy(cast[4].actor , "Margaret Hamilton");
    cast[4].age = 37;
    strcpy(cast[4].role , "Wicked Witch");

    strcpy(cast[5].actor , "Frank Morgan");
    cast[5].age = 49;
    strcpy(cast[5].role , "The Wizard");

    puts("\t\tThe Wizard of Oz Database\n\n");

/*draw the table heading
    printf("%18s\t%3s\t%-15s\n" , "Actor" , "Age" , "Role");
    for(line=0; line<LINE_LENGHT; line++) putchar('-');
    putchar('\n');

/*display the data
    for(x=0; x<6; x++)
        printf("%18s\t%3d\t%-15s\n" ,
               cast[x].actor ,
               cast[x].age ,
               cast[x].role);
*/




    struct oz {
        char actor [18];
        int age;
        char role [16];
        };

    struct oz cast [6] = {              //!3 coloane(struct oz) si 6 randuri
        "Judy Garland" , 17, "Dorothy",
        "Ray Bolger" , 35, "Scarecrow",
        "Bert Lahr" , 44, "Cowardly Lion",
        "Jack Haley" , 40, "Tin Woodsman",
        "Margaret Hamilton", 37, "Wicked Witch",
        "Frank Morgan" , 49, "The Wizard"
        };

    int line, x, y;
    struct oz temp;   //!Variabila temp are tot 3 elemente,
                        //!3 elemente din structura oz

/*swap Margareth and Frank*/
    temp=cast[4];
    cast[4]=cast[5];
    cast[5]=temp;

/*sort by age*/     //!using bubble sort ;-)
                    //!am 2 for-uri
                    //!cast[x] ramane 0 pana cast[y] merge de 6 ori - incearca toate combinatiile

    for(x=0; x<6-1; x++)
        for(y=x+1; y<6; y++)
            if(cast[x].age > cast[y].age)
                {temp=cast[y];
                cast[y]=cast[x];
                cast[x]=temp;
                    };

    puts("\t\tWizard of Oz Database\n\n");

/*draw the table heading*/
    printf("%-18s\t%3s\t%-15s\n" , "Actor" , "Age" , "Role");
    for(line=0; line<LINE_LENGHT; line++) putchar('-');
    putchar('\n');

/*display the data*/
    for(x=0; x<6; x++)
    printf("%-18s\t%3d\t%-15s\n", cast[x].actor , cast[x].age, cast[x].role);



//!DECI FORMULA PT A AFISA O STRUCTURA E VARIABILA[X].(punct)ARRAY-ul din structura


    return 0;
}
