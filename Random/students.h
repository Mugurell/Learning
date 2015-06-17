#include <stdio.h>
#include <stdlib.h>

struct student{
    char id_num[6];
    char name[11];
    char gender;
    int age;
};

int main(void)
{
    struct student studno_1;       //!am declarat variabila studno_1 pentru structura student
    //! studno_1.id_num = "A3214"; // illegal, const char to char[]
    //! studno_1.name = "Smith";   // illegal, const char to char[]

    printf("Enter student ID num (5 max): ");
    scanf("%s", studno_1.id_num);
    printf("Enter student name (10 max): ");
    scanf("%s", studno_1.name);
    studno_1.gender = 'M';
    studno_1.age = 30;

    printf("\n------------------\n");
    printf("ID number: %s\n", studno_1.id_num);
    printf("Name     : %s\n", studno_1.name);
    printf("Gender   : %c\n", studno_1.gender);
    printf("Age      : %d\n", studno_1.age);
    printf("------------------\n");
    return 0;
}
