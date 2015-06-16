#include <stdio.h>

int
main()
{
	enum days{Monday, Tuesday = 22, Wednesday, Thursday,
			  Friday, Saturday, Sunday};
/* Prin faptul ca definesc variabila today de tipul enum days
	nu pot sa pun in today decat zilele din days! */
	enum days today;
	today = Sunday;
	printf("%d day\n", today);


	enum liquid{ounce = 1, cup = 8, pint = 16,
				quart = 32, gallon = 128};
	enum liquid jar;
	jar = quart;
	printf("%d \n", jar);
	jar += pint;
	printf("%d \n", jar);

	return 0;

}