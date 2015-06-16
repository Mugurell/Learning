#include <stdio.h>

#define FALSE 0
#define TRUE !FALSE

int main() {
  char fruit[14];
  FILE *myfile;
  int x;

  /*Does the file exist?*/
  if (!(myfile = fopen("froot.txt", " r"))) {
    puts("\n\tError reading file!");
    return 1;
  }

  /*Read every fruit 1 by 1*/
  while (TRUE) {
    x = fread(&fruit, 14, 1, myfile);
    /* citeste "1" bloc de memorie de "14" bytes
     * caruia ii zici "fruit"
     * din myfile - adica "froot.txt"
    */
    if (x == 0) break;
    printf("%3d: %s\n", ftell(myfile), fruit);
    /*ftell pozitia la care citeste in myfile*/
  }

  fclose(myfile);
  return 0;
}