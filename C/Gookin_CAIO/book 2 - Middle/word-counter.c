#include<stdio.h>
#define SIZE 2000

int main()
{
	int words = 0;
	int i;
	char prop[SIZE] = { '\0' };
	// char prop[SIZE] = "ana are mere";

	printf("Zii ceva smecher : ");
	fgets(prop, SIZE , stdin);
	 printf("_%s_", prop);
	for (i = 0; i < SIZE; i++)
	{
		if (prop[i] == ' ')
		{
			// puts("intra");
			words++;
		}
	}

	words++;
	printf("The prop had %d words", words);


	i = 0;
	int a = ++i;
	printf("\n1st %d", a);

	i = 0;
	int b = i++;
	printf("\n2nd %d", b);

	return (0);

}