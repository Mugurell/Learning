#include <stdio.h>
#define DISTANCE 378921.46     //in kilometers
#define PI 3.14159265358979

int main()
{
	double orbit;
	float miles = DISTANCE*0.621371192;
	orbit=miles*2*PI;
	
	printf("The moon travels %f miles  in one orbit\n" , orbit);
	
	return(0);
		
	}