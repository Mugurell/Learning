#include <stdio.h>

int main(void)
{
	int quantity, price;
	char department[100];

	printf("\nIa zii boss 2 int, si o prop :\n");
	scanf("%d %d %s",&quantity, &price, department );

	printf("\nAi introdus %d, %d, %s\n", quantity, price, department);
	getchar();
	getchar();

	return 0; 
}