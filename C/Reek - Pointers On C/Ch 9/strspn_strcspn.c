/*
** size_t strspn( char const *str, char const *group );
** Numara de cate ori oricare din caracterele din *group
** se gasesc in *str.
**
** size_t strcspn( char const *str, char const *group );
** Numara fiecare caracter din *str care nu se gaseste
** printre caracterele din *group
*/

#include <stdio.h>
#include <string.h>

int matches( char const *str, char const *group );
int unmatched( char const *str, char const *group );

int main(void)
{
	char string[100];
	char group[20];
	int option;

	puts("\nSay something nice");
	fgets(string, 100, stdin);
	puts("\nNow.. What do you want to search from?");
	fgets(group, 20, stdin);
	puts("\nDo you want to count the chars that are repeated - [1]");
	puts("\tor the ones that do not repeat - [2] ?");
	printf("Your option [1] / [2] : ");
	scanf("%d", &option);

	switch(option) {
		case 1:
			printf("\nCool! So there are %d chars repeated!\n", 
				matches(string, group));
		case 2:
			printf("\nCool! So there are %d chars that don't repeat!\n", 
				unmatched(string, group));
		default:
			puts("\n1 or 2.\n\tTough choice huh? :-|");
	}

	return 0;
}

int matches( char const *str, char const *group )
{
	return(strspn(*str, *group ));
}

int unmatched( char const *str, char const *group )
{
	return(strcspn(*str, *group ));
}

