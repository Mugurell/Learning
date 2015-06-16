
#include <stdio.h>
int main()
{
	int tick;

	printf("Variable t is unitialized.\n");

	for (tick = 1; tick < 11; tick = tick + 1)
	{
		printf("\tIn the loop, tick = %d\n", tick);
		 if (tick > 5)
		{
			break;
		}
	}
	printf("After the loop, tick = %d\n", tick + 1);
	return (0);
}