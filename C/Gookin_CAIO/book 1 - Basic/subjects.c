#include <stdio.h>

int main()
{
	char subname[32];
	int iq;
	float wages;

	printf("Input subject name :");
	scanf("%s", &subname);
	printf("Input subject iq :");
	scanf("%d", &iq);
	printf("Input subject hourly wage :");
	scanf("%f", &wages);

	printf("\nSubject\tIQ\twages\n");
	printf("%s\t%i\t%f\t", subname, iq, wages);
	return (0);
}