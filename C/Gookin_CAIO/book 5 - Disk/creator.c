#include <stdio.h>
#include <stdlib.h>		//for exit
#include <ctype.h>		//for toupper
#include <time.h>

#define DELAY 1.4
int
main()
{
    FILE* myfile;
    char c;
    time_t then;

    myfile = fopen("alive.txt", "r");
    /******Verify if the file allready exists******/
    /***Ask the operator if willing to overwrite***/
    if (myfile) {
        puts("ALIVE.TXT allready exists!\n");
        time(&then);
        while(difftime(time(NULL), then) < DELAY)
        	;
        puts("\t...");
        then = time(NULL);
        while (difftime(time(NULL), then) < DELAY)
            ;
        printf("Overwrite it? [Y/N]");
        c = toupper(getchar());
        if (c != 'Y') {
            puts("Okay");
            time(&then);
            while (difftime(time(NULL), then) < DELAY)
                ;
            puts("\tGood-bye!");
           	time(&then);
           	while(difftime(time(NULL), then) < DELAY)
           		;
            fclose(myfile);
            exit(1);
        }
    }

    /**If the operator chose Y, the file will be open in write mode**/
    myfile = fopen("alive.txt", "w");
    if (myfile == NULL) {
        puts("Some kind of a file error");
        time(&then);
        while (difftime(time(NULL), then) < DELAY)
            ;
        puts("Good-bye");
        exit(0);
    }

    fprintf(myfile, "I created a file! It's alive!\n");
    then = time(NULL);
    while(difftime(time(NULL), then) < DELAY)
    	;
    puts("\t...");
    time(&then);
    while(difftime(time(NULL), then) < DELAY)
    	;
    printf("Success!\n\tYou've created a new file on the disk!\n");
    fclose(myfile);

    return 0;
}