#include <stdio.h>

void f1(void);
void f2(void);
void f3(void);
void f4(void);
int main(void)
{
	int ch;
	puts("\nmain");
	
	 while((ch = getchar()) != 'Q') {
	 	if(ch == '\n')
	 		continue;
	 	else if(ch == '1')
	 		f1();
	 	else if(ch == '2')
	 		f2();
	 	else if(ch == '3')
	 		f3();
	 	else if(ch == '4')
	 		f4();
	 	else 
	 		puts(":-P");
	}
	return 0;
}

void f1(void)
{
	puts("\nf1");
	// f2();
}

void f2(void)
{
	puts("\nf2");
	// f3();
}

void f3(void)
{
	puts("\nf3");
	// f4();
}

void f4(void)
{
	puts("\nf4");
}