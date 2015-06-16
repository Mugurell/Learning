/************************************************************************
Write a function void written_amount( unsigned int amount, char *buffer );
that converts the value in amount to words and stores them in the buffer.
This function might be used in a program that prints checks. For example,
if value is 16,312, then the string 
SIXTEEN THOUSAND THRSE HUNDRED TWELVE
should be stored in the buffer. 
It is the callerʹs responsibility to make the buffer large enough. 
************************************************************************/

       
#include <stdio.h>
#include <string.h>

void written_amount(unsigned int amount, char *buffer);

/* A recursive helper function to do the work. */
static void do_one_group(unsigned int amount, char *buffer, char **magnitude);
   
int
main(void)
{
	unsigned int numar;
	char buffer[100];

	puts("\n\tINTEGERS TO WORRRDS\n");
	printf("Enter the number which you want to be transformed:\n\t");
	scanf("%u", &numar);
	puts("Now press enter to see the magic!");
	getchar();
	getchar();

	/*
	** Run the function to fill the buffer, then print it
	*/
	written_amount(numar, buffer);
	puts(buffer);
	putchar('\n');

	return 0;
}


/* 
** Magnitude table for a 32-bit machine.
** (didn't put it in a header for to have all in one file - easier to see)
*/
static char *digits[] = {
	"", "ONE ", "TWO ", "THREE ", "FOUR ", "FIVE ", "SIX ", "SEVEN ",
	"EIGHT ", "NINE ", "TEN ", "ELEVEN ", "TWELVE ", "THIRTEEN ",
	"FOURTEEN ", "FIFTEEN ", "SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ",
	"NINETEEN "
	};

static char *tens[] = {
	"", "", "TWENTY ", "THIRTY ", "FORTY ", "FIFTY ", "SIXTY ", 
	"SEVENTY ", "EIGHTY ", "NINETY "
	};

static char *magnitudes[] = {
	"", "THOUSAND ", "MILLION ", "BILLION "
	};


/* 
** Convert the last e-digit group of amount to words.
** Amount is the value to be converted, buffer is where to put the words,
** and magnitude is the name of the 3-digit group we're working on.
*/
static void
do_one_group(unsigned int amount, char *buffer, char **magnitude)
{
	int value;

	/*
	** Get all the digits beyond the last three. If we have any value 
	** there process those digits first. 
	** Note that they are in the next magnitude.
	*/
	value = amount/1000;
	if(value > 0)
		do_one_group(value, buffer, magnitude+1);

	/*
	** Now process this group of digits. Any hundreds?
	*/
	amount %= 1000;
	value = amount/100;
	if(value > 0) {
		strcat(buffer, digits[value]);
		strcat(buffer, "HUNDRED ");
	}

	/*
	** Now do the rest of the value.
	** If less than 20, treat it as a single digit
	** to get the teens names.
	*/
	value = amount%100;
	if(value >= 20) {
		/*
		** Greater than 20.
		** Do a tens name and leave the units to be printed next.
		*/
		strcat(buffer, tens[value/10]);
		value %= 10;
	}
	if(value > 0)
		strcat(buffer, digits[value]);

	/*
	** If we had any value in this group at all, print the magnitude.
	*/
	if(amount > 0)
		strcat(buffer, *magnitudes);	
}


void
written_amount(unsigned int amount, char *buffer)
{
	if(amount == 0)
		/*
		** Special case for 0.
		*/
		strcpy(buffer, "ZERO");
	else {
		/*
		** Store an empty string in the buffer, then begin.
		*/
		*buffer = '\0';
		do_one_group(amount, buffer, magnitudes);
	}
}

