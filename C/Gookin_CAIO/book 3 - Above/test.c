#include <stdio.h>
#define DAYS 5

int main()
{
    int temp [DAYS];
    int day;
    int total = 0;

    for(day=0; day<DAYS; day++)
    {
        printf("What was the approximate temperature %d days ago? - " , day+1);
        scanf("%d" , &temp[day]);
        total += temp[day];
    }

    float average = total/DAYS;

    printf("\n\nThe results just came in...\n\n");

    for(day=0; day<DAYS; day ++)
        printf("%d days ago the temperature was %d\n" , day+1, temp[day]);

    printf("\n\n\tSo the average would be.....\n %20.2f degrees ...\n\n" , average);

    if(average<10)
        puts("Brrr.. jerrr!");
    else if(average>32)
        puts("Canicula, pffff..");
    else if(average<20)
        puts("Brrr... friggg..!");
    else
        puts("Numa bine, vreme perfecta!");


    return 0;
}
