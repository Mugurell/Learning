#include <stdio.h>
#include <string.h>

int main()
{
    struct date {
        int day;
        int month;
        int year;
        }birthday;

    struct family {
        char name[20];
        struct date birthday;    //!birthday e variabila lu' date (de mai sus)
    }me, Doina;

/*Fill in Doina's data here*/
    strcpy(Doina.name, "Stoica Doina");
    Doina.birthday.day = 12;
    Doina.birthday.month = 06;
    Doina.birthday.year = 1961;

/*Enter your own data here*/
    printf("Enter your date of birth here %c ", 16);
    scanf("%d" , &me.birthday.day );
    printf("Now enter here the month in which you were born %c " , 16);
    scanf("%d" , &me.birthday.month);
    printf("And the year please... %c " , 16);
    scanf("%d" , &me.birthday.year);
    puts("\n\n\t....");
    printf("\t...\nI almost forgt, what is your name?");
    scanf("%s" , me.name);


    printf("\n\n\n\tOk, so, the results just came in ...\n\n");
    printf("%s was born on %d-%d-%d\n", me.name,\
                                      me.birthday.day,\
                                      me.birthday.month,\
                                      me.birthday.year);
    puts("\n\t.. and\n");
    printf("%s was born on %d-%d-%d\n",\
           Doina.name,\
           Doina.birthday.day,\
           Doina.birthday.month,\
           Doina.birthday.year
           );

    getchar();
    getchar();

    return 0;
}
