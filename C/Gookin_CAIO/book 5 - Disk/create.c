#include <stdio.h>

int main()
{
    FILE *myfile;

    myfile = fopen("alive.txt", "w");		//v. pg 578 in gookin
    if (!myfile) {
        puts("Some kind of file error!");
        return 1;
    }

    fprintf(myfile, "I created a file! It's alive!\n");
    fclose(myfile);

    return 0;
}