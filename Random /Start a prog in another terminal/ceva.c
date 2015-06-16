#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
 

	printf ("Who are you?");
	char nume[100];
	fgets(nume, 100, stdin);
	printf("Deci te cheama %s..", nume);
	printf("my process ID is %d\n", getpid());
	printf("\nI'm now gonna kill this terminal");
	getchar();
	system("pkill -n gnome-terminal");

	
	return 0;

}
