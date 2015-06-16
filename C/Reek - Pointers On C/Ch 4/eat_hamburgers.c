#include <stdio.h>
#include <ctype.h>

void hunger(void);
void eat(void);

int main()
{
	hunger();

	return 0;
}

void hunger(void)
{
	puts("\n\tYou hungry ma man? Y/N");

	char ch = toupper(getchar());

	switch(ch) {
		case 'Y':
			puts("Really?\n\tThen eat!");
			eat();
			break;
		case 'N':
			printf("Good!\n\tFood's expensive... people are fat...");
			printf("\nYou're doing the right thing by not eating!\n\n");
			break;
		default:
			printf("\"Y\"es or \"N\"o?");
			printf("\nSo hungry you can't even type Y/N");
			printf("\nHere's some leftovers... They are free!");
			puts("\n\tThis time!");
			eat();
	}
}

void eat(void)
{
	printf("Ham - ham...");
	printf("\n\tYummy - yummy");
	puts("\n\n");
}