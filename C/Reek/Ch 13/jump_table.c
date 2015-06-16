/*
** Use a jump table for a few basic marh functions
** (emulate what a pocket calculator would do)
*/

#include <stdio.h>

double add(double, double);
double sub(double, double);
double mul(double, double);
double divi(double, double);

double (*oper_func[]) (double, double) = {add, sub, mul, divi};


int main(void)
{
	int a, b;
	char choice;

	puts("\nThis great calculator uses a jump table");
	puts("to examplify how a pocket calculator works");
	puts("And to provide practice using jump tables..\n");

	puts("So it can perform the 4 basic operations.\n");

	puts("Getting down to business, enter 2 numbers "
		"separated by commas\t\t");
	scanf("%d," "%d,", &a, &b);
	while (getchar() != '\n')
		;

	puts("Now what do you want to do with them my man?");
	printf("\t%-9s - A\n", "Add");
	printf("\t%-9s - S\n", "Substract");
	printf("\t%-9s - M\n", "Multiply");
	printf("\t%-9s - D\n%*c", "Division", 6, ' ');

	choice = getchar();
	while (getchar() != '\n')
		;
	if (choice >= 'a' && choice <= 'z')
		choice += 'A' - 'a';

	enum {A, S, M, D} functions;
/* Altfel functions ar fi citit valoarea in ascii
** ex: 65, etc... */ 
	if (choice == 'A') functions = A;
	else if (choice == 'S') functions = S;
	else if (choice == 'M') functions = M;
	else if (choice == 'D') functions = D;
	else {
		puts("Invalid choice. \n\tBye!");
		return 1;
	}

	//functions = choice;

	printf("\nThe result is .. %.2f\n\n", oper_func[functions](a, b));

	return 0;
}


double add(double a, double b)
{
	return a+b;
}

double sub(double a, double b)
{
	return a-b;
}

double mul(double a, double b)
{
	return a*b;
}

double divi(double a, double b)
{
	return a/b;
}


