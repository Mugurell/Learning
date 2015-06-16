#include <stdio.h>

#define BUFSIZE 200

int main(int argc, char *argv[]) {
	FILE *myfile;
	char buffer[BUFSIZE+1];
	int x = 0;

/*check for proper no. of arguments*/
	if(argc < 2) {
		puts("Invalid command - Not enough arguments!");
		printf("Here is the format %c\n", 25);
		puts("VIEW2 filename");
		return 1;
	}

/*check if file exists*/
	if(!(myfile = fopen(argv[1], "r"))) {
		puts("Error reading file");
		return 1;
	}

/*display the file's guts*/
	printf("**After file opened, file pointer = %d\n**", ftell(myfile));
	while(fgets(buffer, BUFSIZE, myfile)) {
		printf("%s", buffer);
		printf("**Wrote record %d, file pointer = %d\n**", x++, ftell(myfile));
	}

	fclose(myfile);
	return 0;
}