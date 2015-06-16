#include <stdio.h>

int main(void) {
  char froot[25][14] = {
      "Apple",      "Avocado", "Banana",    "Blackberry",  "Boysenberry",
      "Cantaloupe", "Cherry",  "Coconut",   "Cranberry",   "Cumquat",
      "Grape",      "Guava",   "Mango",     "Marionberry", "Melon",
      "Orange",     "Papaya",  "Peach",     "Pear",        "Persimmon",
      "Pineapple",  "Plum",    "Raspberry", "Strawberry",  "Watermelon"};
  FILE *f;
  int x;

  if (!(f = fopen("froot.txt", "w"))) {
    puts("Error creating file");
    return 1;
  }


/* file pointer indicates a position or offset inside the file
 * at which information is being read. (ftell).
*/
  printf("After file opened, file pointer = %d\n", ftell(f));

  for (x = 0; x < 25; x++) {
    fwrite(froot[x], 14, 1, f);
    printf("Wrote record %d, file pointer = %i\n", x, ftell(f));
  }

  fclose(f);
  return 0;
}