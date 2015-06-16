#include <stdio.h>

int main()
{
	long int humongous;
	char chuck;

	for (humongous = 65; humongous <= 90; humongous ++)
	{
	printf("\t%d" , humongous);
	chuck = (char)humongous;
	putchar(chuck);

	}
	return (0);
}