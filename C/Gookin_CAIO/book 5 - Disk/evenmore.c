#include <stdio.h>
#include <time.h> 
#include <string.h>		//for strlen
#include <stdlib.h> 	//for exit
#include <Windows.h>

#define DELAY 100

void read(void);
void write(void);
void append(void);
void delay (void);

int main()
{
	char c;

	puts("\t.TXT FILE MODIFIER PROGRAM\n\n");
	puts("So tell me, what do you wanna do my man?");
	puts("\t1) R - Read an existing file");
	puts("\t2) W - Write a new file");
	puts("\t3) A - Append to an existing file");
	puts("\t4) Q - Quit this program");

	c = getchar();
	if(c>=97 && c<=122) c-='a' - 'A';
	printf("**You entered %c***\n", c);
	switch(c) {
		case '4':
		case 'Q':
			puts("\nDid I offended you in some way?");
			delay();
			puts("\t...");
			delay();
			puts("BYE!");
			exit(1);
		case '1':
		case 'R':
			read();
			break;
		case '2':
		case 'W':
			write();
			break;
		case '3':
		case 'A':
			append();
			break;
	}

	return 0;
}


void delay(void)
{
//	time_t then = time(NULL);
//	while(difftime(time(NULL), then) < DELAY)
//			;

	Sleep(100000);
}


void read(void)
{	
	FILE *myfile;
	char name[100];			//contine adresa/numele fisierului fara extensie
	char adress[100];		//contine adresa/numele complet al fisierului
	char c;

	delay();
	puts("\nOkey..");
	delay();
	puts("\nPlease tell me file's name or it's complete adress");
	printf("( Without the extension \".txt\" ) %c\n", 25);
	while((c=getchar()) != '\n')
		continue;
	gets(name);

	sprintf(adress, "%s.txt", name);

	myfile = fopen(adress, "r");
	if(!myfile) {
		puts("Some kind of a file error");
		exit (1);
	}
	delay();
	puts("Ok, here it comes..\n");
	delay();
	while((c = fgetc(myfile)) != EOF)
		fputc(c, stdout);

	fclose(myfile);
	delay();
	puts("\n\tThat's all folks!");
}

void append(void)
{
	FILE *myfile;
	char name[100];			//contine adresa/numele fisierului fara extensie
	char adress[100];		//contine adresa/numele complet al fisierului
	char c;

	delay();
	puts("\nOkey..");
	delay();
	puts("Please tell me file's name or it's complete adress");
	printf("(Without the extension \".txt\" %c\n", 25);
	while((c=getchar()) != '\n')
		continue;
	gets(name);
	sprintf(adress, "%s.txt", name);

	myfile = fopen(adress, "a");
	if(myfile == NULL) {
		puts("Some kind of a file error");
		exit (1);
	}
	if(myfile) {
		puts("...");
		delay();
		puts("Okey, all good");
		puts("Now type what you want to be appended");
		printf("(Press Ctrl+Z when you want to stop)   %c\n", 25);
		while((c=fgetc(stdin)) != EOF)
			fputc(c, myfile);

	}

	fclose(myfile);
	puts("\n\tDone! my brother\n\n");
}

void write (void)
{
	char constr[] = "In construnction";
	int x, len = strlen(constr);

	printf("\n\n\t");
	for(x=0; x<len; x++) {
		putchar('*');
	}
	printf("\n\tIN CONSTRUCTION\n\t");
		for(x=0; x<len; x++) {
		putchar('*');
	}

	delay();
	puts("\n\n(Please refer to the append option)");
	delay();
	puts("Goodbye!");
}