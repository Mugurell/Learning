#include <stdio.h>
#include <time.h>

#define DELAY 5

void pause(void)
{
    time_t then;

    time(&then);
    while(difftime(time(NULL), then) < DELAY)
        ;
//! difftime calculates the difference in seconds between beginning and end
//!     in cazul asta time(NULL) - then
//! and returns the result in seconds as a floating-point value of type double.
}

int main()
{

    int x;

    for(x=10; x>0; x--)
    {
        printf("%d\n", x);
        pause();
    }
    puts("\n\tBlast Off !\n\n\n");

    return 0;
}
