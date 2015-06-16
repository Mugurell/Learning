#include <stdio.h>

#define RECSIZE 14

int main() {
	FILE *f;
	char froot[RECSIZE];
	int record, offset;

	if(!(f = fopen("froot.txt", "r"))) {
		puts("Error reading file\n");
		return 1;
	}

/****Get record 12, record size = RECSIZE ***/
	record = 12;
	offset = record * RECSIZE;

/****Position the file pointer at a specific location*****/
/**** v. Gorkin, pg 579-580 *****/ 
	fseek(f, offset, SEEK_SET);

/**** read one block of memory of size "RECSIZE" from that location ***/
	fread(froot, RECSIZE, 1, f);
	printf("%d : %s\n", (ftell(f))/RECSIZE, froot);

	fclose(f);
	return 0;
}
