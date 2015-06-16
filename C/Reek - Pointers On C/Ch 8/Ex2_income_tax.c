/* The U.S. federal income tax for single people in 1995 was computed
according to the following rules: 
______________________________________________________________________
If Your Taxable |               |                    |  of the Amount 
income Is Over  |  But Not Over |   Your Tax is      |    Over
----------------------------------------------------------------------
		$0      |   $23,350 	|		15% 		 |		$0 
	23,350 		|	56,550 		|  $3,502.50 + 28% 	 |	  23,350 
	56,550 		|	117,950 	|  12,798.50 + 31% 	 |	  56,550 
	117,950 	|	256,500 	|  31,832.50 + 36% 	 |    117,950 
	256,500 	|	  ––  		| 81,710.50 + 39.8%  |	  256,500 
 ---------------------------------------------------------------------

Write the function prototyped below: 
float single_tax( float income );

The argument is taxable income, and the function returns the appropriate
amount of tax. 
*/

#include <stdio.h>

float single_tax(float income);

int main(void)
{
	float income;

	puts("\n\tI.R.S. tax calculator\n");
	puts("Hello Sir!");
	printf("What was your taxable income last year?\n\t");
	scanf("%f", &income);

	puts("\nNice!");
	printf("Looks like you owe us.. $%.2f !", single_tax(income));
	printf("\n\tCa-ching!\n\n");

	return 0;
}

float single_tax(float income)
{	
	float taxable_amount;

	if( income == 0 )
		return 0;
	else if( income > 0 && income <= 23350 ) 
		return( (income*15) / 100 );
	else if( income > 23350 && income <= 56550) {
		taxable_amount = income - 23350;
		return( ((taxable_amount*28) / 100) + 3502.50);
	}
	else if( income > 56500 && income <= 117950) {
		taxable_amount = income - 56500;
		return( ((taxable_amount*31) / 100) + 12798.50);
	}
	else if( income > 117950 && income <= 256500) {
		taxable_amount = income - 117950;
		return( ((taxable_amount*36) / 100) + 31832.50);
	}
	else {
		taxable_amount = income - 256500;
		return( ((taxable_amount*398) / 1000) + 81710.50);
	}

	return 1;
}