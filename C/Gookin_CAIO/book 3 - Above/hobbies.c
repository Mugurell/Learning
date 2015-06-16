#include <stdio.h>
#include <string.h>

//!Vezi ce se intampla daca de-comentezi ..chestiile comentate
/*! hint "For each variable of the
struct person type that’s created, only one of the union items (sports,
music, or television) can be used.
*/

int main()
{
    struct person
    {
        char name[50];
        int age;
        union
        {
            struct
            {
                char game [25];
                int jersey_number;
            } sports;
            struct
            {
                char instrument[25];
                int years_practice;
            } music;
            struct
            {
                int hours_week
            } television;
        } hobby;
    } a, b, c;

    strcpy(a.name, "Alex");
    a.age = 17;
    strcpy (a.hobby.music.instrument, "Guitar");
    a.hobby.music.years_practice = 3;

    strcpy(b.name, "Gheorghe");
    b.age = 23;
    strcpy(b.hobby.sports.game, "Football");
    b.hobby.sports.jersey_number = 11;

    strcpy(c.name, "Vasily");
    c.age = 15;
    c.hobby.television.hours_week = 60;
//    strcpy(c.hobby.sports.game, "Tenis");
  //  c.hobby.sports.jersey_number = 11;

    printf("Person A is %s, who is %d years old.\n", a.name, a.age);
    printf("%s has played %s for %d years.", a.name, a.hobby.music.instrument,\
           a.hobby.music.years_practice);

    puts("\n\n");

    printf("Person B is %s, who is %d years old.\n", b.name, b.age);
    printf("%s has played %s and for 2 years he is wearing no. %d on his t-shirt.",\
            b.name, b.hobby.sports.game,\
           b.hobby.sports.jersey_number);

    puts("\n\n");

    printf("Person C is %s, who is %d years old.\n", c.name, c.age);
    printf("%s watches TV %d hours average a week.", c.name, c.hobby.television,\
           c.hobby.television.hours_week);
 /*   printf("\n%s has played %s and for 2 years he is wearing no. %d on his t-shirt.",\
            c.name, c.hobby.sports.game,\
           c.hobby.sports.jersey_number);
*/
    getchar();

    return (987654);
}
