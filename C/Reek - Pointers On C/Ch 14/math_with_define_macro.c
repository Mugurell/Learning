#include <stdio.h>

#define ADD(a, b)  ((a)+(b))
#define SUB(a, b)  ((a)-(b))
#define DIV(a, b)  ((a)/(b))
#define MUL(a, b)  ((a)*(b))
#define BIG(a, b)  ((a)>(b)? (a) : (b));
#define CLEAN 	while (getchar() != '\n');
#define CASE 	break;case


int main(void)
{
	int a, b, result;
	char ch;

	printf("Enter 2 numbers as arguments to basic math operations\n\t\t-> ");
	scanf("%d %d", &a, &b);
	CLEAN
	puts("\nNow what do you want to do with them, my man?:");
	puts("\tB - Who's bigger");
	puts("\tA - Add");
	puts("\tS - Substract");
	puts("\tD - Division");
	printf("\tM - Multiplication\n\t\t");
	ch = getchar();
	CLEAN
	if (ch >= 'a' && ch <= 'z')
		ch += 'A' - 'a';
	switch (ch) {
		CASE 'A': result = ADD(a, b);
		CASE 'S': result = SUB(a, b);
		CASE 'D': result = DIV(a, b);
		CASE 'M': result = MUL(a, b);
		CASE 'B': result = BIG(a, b);
		printf("ch is %c\n", ch); break;
		default : puts("Sorry, can't do that!\n"); break;
	}
	puts("\nSure!");
	printf("The result is %d.\n\n", result);

	return 0;
}
