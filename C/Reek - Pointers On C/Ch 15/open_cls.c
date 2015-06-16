#if !defined _stdio_h
#include <stdio.h>
#include <stdlib.h>
#endif

/*
** Process each of the files whose names appear on the command line.
*/

int main(int ac, char** av)
{
    int exit_status = EXIT_SUCCESS;
    FILE* input;
    char ch;

    /*
	** While there are more names..
	*/
    while (*++av != NULL) {
        /*
		** Try opening the file
		*/
        input = fopen(*av, "r");
        if (input == NULL) {
            perror(*av);
            exit_status = EXIT_FAILURE;
            continue;
        }

        /*
		** Process the file here..
		*/
        while ((ch = fgetc(input)) != EOF) {
            fputc(ch, stdout);
        }

        /*
		** Close the file (don't expect any errors here).
		*/
        if (fclose(input) != 0) {
            perror("fclose");
            exit(EXIT_FAILURE);
        }
    }
    return (exit_status);
}