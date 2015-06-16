
#include <stdio.h>
#include <stdlib.h>		/*necessary for system to work*/

int main()
{
    puts("\n\tPress Enter to see a listof files:");
    getchar();
    system("dir");
    puts("Done!");

    return 0;
}