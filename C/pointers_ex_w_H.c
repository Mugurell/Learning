#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *name;
	int age;
	char *address;
} Person;

#define CLEAN while(getchar() != '\n');

int main(void)
{
	Person *pers;
	int nr;

	printf("How many persons do you want to store? ");
	scanf("%d", &nr);
	CLEAN

	pers = (Person*)malloc(nr * sizeof(Person));
	if (pers == NULL) {
		perror("Heroare:");
		exit(1);
	}

// Cu alte cuvinte, mai sus am creat un array de nr structuri de tipul
//Person, structuri catre care pointeaza pers.



	int x;

	char buffer[500];
	puts("Enter data:");
	for (x = 0; x < nr; x++) {
		printf("Person %d name: ", x+1);
		fgets(buffer, 500, stdin);
		int size = strcspn(buffer, "\n");
		pers[x].name = (char *)malloc(size * sizeof(char));
		strncpy(pers[x].name, buffer, size);
		pers[x].name[size] = '\0';

		printf("Enter person %d's age: ", x+1);
		scanf("%d", &pers[x].age);
		CLEAN

		printf("Enter persons %d's address:\n\t", x+1);
		fgets(buffer, 500, stdin);
		size = strcspn(buffer, "\n");
		pers[x].address = (char *)malloc(size * sizeof(char));
		strncpy(pers[x].address, buffer, size);
		pers[x].address[size] = '\0';
		putchar('\n');
	}

	for(x = 0; x < nr; x++) {
		printf("\nPerson %d:", x+1);
		printf("\n\tName: %s",  pers[x].name);
		printf("\n\tAge: %d", pers[x].age);
		printf("\n\tAddress: %s", pers[x].address);
	}
	putchar('\n');

	for (x = 0; x < nr; x++) {
		free(pers[x].name);
		free(pers[x].address);
	}
	free(pers);

	return 0;
}