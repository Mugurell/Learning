#include <stdio.h>

#define N_VALUES 5

int main(void)
{
	float values[N_VALUES];
	float *vp;

	for(vp = &values[0]; vp < &values[N_VALUES]; )
		*vp++ = 14;

	printf("\n%f\n%f\n%f\n%f\n%f\n%f\n", values[N_VALUES], values[1], values[2],
									values[3], values[4], values[N_VALUES]);

	return 0;
}