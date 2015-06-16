#include <stdio.h>

int main(void)
{
/******************** My version *******************
	signed char sum = -1;
	int c;
	int checked = 0;

	while ((c = getchar()) != EOF) {
		if (checked == 0) {
			sum += c;
			putchar(c);
	//		checked = 1;
		}
		if (c == '\n')
			checked = 1;
		if (checked == 1) {
			printf("\n\tSum is %d.\n", sum);
			checked = 0;
		}
	}
	return 0;
*******************************************************/

/******************** My 2nd version *******************/
char sum = -1;
int c;

	while((c = getchar()) != EOF) {
		putchar(c);
		sum += c;
		if(c == '\n') {
			printf("\n\tSum is %d.\n", sum);
			sum = -1;
		}
	}
	return 0;

/***************** Reek's version *********************
	int c;
	char sum = -1;

	while((c = getchar()) != EOF) {
		putchar(c);
		sum += c;
	}

	printf("\n\t%d\n", sum);

	return 0;
*********************************************************/
}