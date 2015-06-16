#include <stdio.h>

int main(void)
{
	int ones;
	unsigned value = 15;
	printf("\n**value is  %d**\n", value);

	/*
	** While the value still has some 1-bits in it...
	*/
	for(ones = 0; value != 0; value >>= 1)
		if(value%2 != 0)
			ones +=1;

	printf("\nValue is %d, return is %d\n\n", value, ones);

return 0;
}