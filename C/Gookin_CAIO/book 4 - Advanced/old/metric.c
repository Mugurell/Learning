#include <stdio.h>

#define KPM 1.609344

int main()
{
    float kilometers, miles;
    float *pmiles;      //!am declarat un pointer pentru a examina un float
    float *k_adress;

    printf("Enter a value in miles %c ", 16);
    scanf("%f" , &miles);
    while(getchar() != '\n')
        continue;

    puts("\n\n\t");

    kilometers = miles*KPM;

    printf("%.2f miles works out to %.2f kilometers.\n" , miles, kilometers);

    puts("\n\n");
    pmiles = &miles;
    k_adress = &kilometers;
    printf("Variable 'miles' is %d bytes long at %p adress.\n" ,\
            sizeof(miles) , pmiles);
    printf("Variable 'kilometers' is %d bytes long at %p adress." ,\
            sizeof(kilometers) ,k_adress );

    getchar();

    exit (67890);
}
