#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc <= 2)
        puts("\nNot enough arguments\n");
    else {
        printf("\nSo you had %d arguments\n\n", argc);
        if (argc == 3 || argc == 4) {
            printf("I shall now work on %d and %d arguments..", 2, 3);
            printf("That being %s and %s", argv[2], argv[3]);
        } else {
            printf("I shall now work on %d and %d arguments..\n", 2, argc - 1);
            printf("That being %s and %s", argv[2], argv[argc-1]);
        }
    }

    return 0;
}