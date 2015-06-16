#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGHT 40

int main(void)
{
	struct cast {
		char actor[18];
		int age;
		char role[16];
	};
	typedef struct cast OZ;  //Create typedef shortcut OZ
	OZ *star;				 //create structure pointer
	int line;

/*Get memory chunk*/
	star = (OZ *)malloc(sizeof(OZ));	//get OZ memory chunk

	if(star == NULL)
	{
		puts("ERROR : Not enough memory");
		return 0;
	}

	strcpy(star->actor, "Judy Garland");
	star->age = 17;
	strcpy(star->role, "Dorothy");

	puts("\tWizard of Oz Database\n\n");


/*draw the table heading*/
	printf("%-18s %3s	%-15s\n", "Actor", "Age", "Role");
	for(line =0; line<LINE_LENGHT; line++)	putchar('-');
	putchar('\n');


/*display the data*/
	printf("%-18s%3d	%-15s\n",
	 star->actor, star->age, star->role);



	getchar();
	return 0;
}