#include <stdio.h>
#include <stdlib.h>

void finish (void);
void spiffy (void);
void animation (void);

int main()
{
    atexit(animation);
    atexit(spiffy);
    atexit(finish);     //! AT EXIT run functia finish


    puts("Press Enter to begin shutting down this program");
    getchar();

//    finish();

    exit(1);
}

void finish(void)
{
    puts("\nThis is the function that looks under");
    puts("\tthe hard drive for any missing bits...");
}

void spiffy (void)
{
    puts("\n\nThis function cleans up the keyword.");
}

void animation (void)
{
    puts("\n\nAs a final trick, the Taco Bell dog will dance");
    puts("\tacross your monitor with this function.");
}
