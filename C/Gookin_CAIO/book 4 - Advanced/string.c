#include <stdio.h>

int main(void)
{
	char *t, text[] = "Going! Going! Gone";
	t = text;

	while(*t)
	{
		puts(t++);		//sari cate un bloc de memorie
	}

	getchar();
	return 0;
}