#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 255

int main(int argc, char *argv[]) {
	FILE *myfile;
	char buffer[BUFFSIZE+1];		/*storage*/

/* check for proper no. of arguments*/
	if(argc<2) {
		puts("Missing filename!");
		printf("Here is the format %c\n", 25);
		puts("VIEW filename");
		exit(1);
	}

/*Does the file exist?*/
	if(!(myfile = fopen(argv[1] , "r"))) {
		printf("Error opening \"%s\"\n", argv[1]);
		exit(1);
	}

/*display the file's guts*/
	while(fgets(buffer, BUFFSIZE, myfile)) printf("%s", buffer);

	fclose(myfile);
	return 0;
}