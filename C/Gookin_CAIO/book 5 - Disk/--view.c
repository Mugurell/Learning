#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1

int main(int argc, char *argv[])
{
	FILE *viewfile;
	char buffer[BUFSIZE+1];		/*storage*/

/*check for proper no. of arguments*/
	if (argc<2) {
		puts("Missing filename!");
		puts("Here is the format:");
		puts("VIEW filename");
		exit (1);
	}

/*Does the file exist?*/
	viewfile = fopen(argv[1], "r");
	if(!viewfile)
	{
		printf("Error opening \"%s\"\n", argv[1]);
		exit (1);
	}

/*display the file's guts
(read until EOF/new line/BUFSIZE-1)
*/
/* fgets zice:
	1 - unde sa stocheze
	2 - cat sa citeasca
	3 - de unde sa citeasca
*/
	while(fgets(buffer, BUFSIZE, viewfile))
		printf("%s", buffer);
	
	fclose(viewfile);
	return 0;
}