#include <stdio.h>
#include <time.h>

int main()
{
    FILE* scores;
    int s [10] = {1000, 990, 985, 984, 944, 932, 931, 929, 928, 927};
    int x;
    time_t then;

    scores = fopen("scores.dat", "w");
    if (scores == NULL) {
        puts("Error creating file");
        return 1;
    }

 //   fprintf(scores, "%d", s);

    for(x=0; x<10; x++)
    	fprintf(scores, "%d\n", s[x]);
    fclose(scores);

    time(&then);
    while (difftime(time(NULL), then) < 1.3)
        ;
    puts("...");
    then = time(NULL);
    while (difftime(time(NULL), then) < 1.3)
        ;
    puts("High score saved to disk!\n");
    return 0;
}