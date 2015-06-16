#include <stdio.h>

#define RECSIZE 14

int main(void) {
  FILE *myfile;
  char froot[RECSIZE + 1];
  int record;

  if (!(myfile = fopen("froot.txt", "r"))) {
    puts("Error reading file");
    return 1;
  }


  for (record = 0; record <25 ; record ++) {
//  	offset = record * RECSIZE;
    fread(froot, RECSIZE, 1, myfile);
  	fseek(myfile, 0, SEEK_CUR);
    printf("%d - %s\n", (ftell(myfile)) / RECSIZE, froot);
  }

  fclose(myfile);
  return 0;
}