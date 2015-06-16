/*
** Process command-line arguments
*/

#include <stdio.h>

#define 	TRUE 	1

/* 
** Prototypes for functions that do real work.
*/
void process_standard_input(void);
void process_file(char *file_name);

/*
** Option flags, default initialization is FALSE
*/
int option_a, option_b /* etc */;

void main(int argc, char **argv)
{
	/*
	** Process option arguments: 
	** skip to the next argument (acc to Reek, first argument
	**							 should be program's name)
	** and check that it begins with a dash.
	*/
	while (*++argv != NULL && **argv == '-') {
		/*
		** Check the letter after the dash.
		** The first indirection goes to where argv points, 
		** and this location is incremented. -> skip the dash.
		** The last indirection follows the incremented pointer.
		*/
		switch (*++*argv) {
			case 'a':	option a = TRUE;	break;
			case 'b': 	option_b = TRUE; 	break;
			/* etc */
		}
	}
	// Cu alte cuvinte whileul se plimba in *argv.
	// 1 - verifica daca e diferit de NULL, si daca incepe cu '-'
	// 2 - daca da, in switch se incrementeaza pozitia lui '-'
	// 3 - dupa ce switchul s-a executat, se intoarce la while.

	/*
	** Process file name arguments
	*/
	if (*argv == NULL)
		process_standard_input();
	else {
		do {
			process_file(*argv);
		} while (*++argv != NULL);
	}
}