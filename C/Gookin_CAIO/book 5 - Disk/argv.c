#include <stdio.h>

int main(int argc, char* argv[]) {
  int x;

  puts("Command line arguments:");
  for (x = 0; x < argc; x++)
    printf("Argument #%d: %s\n", x, argv[x]);

  return 0;
}
