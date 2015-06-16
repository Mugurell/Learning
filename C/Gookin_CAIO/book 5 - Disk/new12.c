#include <stdio.h>

#define RECSIZE 14

int main(void) {
	FILE *myfile;
	char newfroot[RECSIZE] = "Snozberry";
	int record, offset;

	if(!(myfile = fopen("froot.txt", "r+"))) {
		puts("Error opening file");
		return 1;
	}

/*** Replace record 12, record size = RECSIZE ***/
	record = 12;
	offset = record * RECSIZE;
	fseek(myfile, offset, SEEK_SET);

	fwrite(newfroot, RECSIZE, 1, myfile);
	fclose(myfile);

	return 0;
}