#include <stdio.h>
#include <time.h>

#define DELAY 2

int main()
{
	char name[100];

	putchar('\n');
	printf("What's your name bo$$? %c ", 16);
	fgets(name, 100, stdin);


/*****Add some moments of tension******/
	time_t then = time(NULL);
	while(difftime(time(NULL), then) < DELAY)
		;
	puts("\nReally?\n");

	time(&then);
	while(difftime(time(NULL), then) < DELAY)
		;
	puts("Okey..\n");

	time(&then);
	while(difftime(time(NULL), then) < DELAY)
		;
	puts("\tBye then...\n");



/*******save the entered name in a separate file on the disk******/
	FILE *myfile;
/*If all goes well, fopen() returns a value of the FILE type. 
 * FILE is a “typedef’d” variable defined in STDIO.H. 
 * It’s a pointer variable that provides a shortcut reference,
 * or handle, to represent the open file. 
 *When FILE is equal to NULL, the fopen() command has failed.
*/
	myfile = fopen("yourname.txt", "w");

/* if fopen returned null*/
	if(!myfile) {
		puts("Some kind of file error");
		return 1;
	}
/* if fopen didn't returned null*/

	struct tm *t;
	time_t now;
	now = time(NULL);
	t = localtime(&now);

	char *zile[] = {
		"Sun",
		"Mon",
		"Wed",
		"Thu",
		"Fri",
		"Sat",
		"Sun"
	};
	fprintf(myfile, "Today is %s, %d/%02d/%d\n",
								zile[(t->tm_wday)-1],
								t->tm_mday,
								t->tm_mon,
								(t->tm_year) + 1900);
	fprintf(myfile, "Time is - %d:%02d:%02d\n",
								 t->tm_hour,
								 t->tm_min,
								 t->tm_sec);
	fprintf(myfile, "Operator's name is - %s\n", name);
	fclose(myfile);

	return 0;
}