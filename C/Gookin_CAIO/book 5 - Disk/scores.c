#include <stdio.h>
#include <time.h>
#include <stdlib.h> //necesar pt functia system

int main(void)
{
    FILE* scores;
    int s[10];
    int x;
    time_t then;

    scores = fopen("scores.dat", "r");
    if (!scores) {
        puts("Error opening file");
        return 1;
    }

   // fscanf(scores, "%d", &s);
    for(x=0; x<10; x++)
    	fscanf(scores, "%d", &s[x]);
    fclose(scores);

    then = time(NULL);
    while (difftime(time(NULL), then) < 1.3)
        ;
    puts("\t...");
    time(&then);
    while (difftime(time(NULL), then) < 1.2)
        ;
    //printf("The high score is %d\n", s);
    printf("Top 10 Highscores %c\n", 25);
    for(x=0; x<10; x++)
    	printf("\t%d\n", s[x]);

    printf("\nDo you want to clear the highscore? Y/N %c ", 16);
    x = getchar();
    switch (x) {
    case 'y':
    case 'Y':
        system("del scores.dat");
        then = time(NULL);
        while(difftime(time(NULL), then) < 1.3)
        	;
        puts("\t...");
        time(&then);
        while(difftime(time(NULL), then) < 1.3)
        	;
        puts("\tscores.dat successfully deleted");
        return 0;
    case 'n':
    case 'N':
        puts("\tOk... ");
        return 0;
    default:
        puts("Guess pressing Y or N is too much of a hassle for you..");
        time(&then);
        while (difftime(time(NULL), then) < 1.2)
            ;
        puts("\t Bye!");
    }

    return 0;
}