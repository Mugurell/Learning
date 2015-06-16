#include <stdio.h>

#define RECSIZE 14

int main(void) {
  FILE *myfile;
  char froot[RECSIZE + 1];
  int record, offset;

  if (!(myfile = fopen("froot.txt", "r"))) {
    puts("Error reading file");
    return 1;
  }

  for (record = 0; record < 25; record += 2) {
    offset = record * RECSIZE;
    fseek(myfile, offset, SEEK_SET);
    fread(froot, RECSIZE, 1, myfile);
    printf("%d : %s\n", (ftell(myfile)) / RECSIZE, froot);
  }

  fclose(myfile);
  return 0;
}