#include <stdio.h>
#include <time.h>

void time_1(void);
void time_2(void);

int main()
{
    time_2();

    return 0;
}

void time_1(void)
{
    time_t now;     //!another variable type, just like int, char, etc

  /*  time(&now);    */      //!ambele notatii merge pentru a baga o copie
    now = time(NULL);       //! a timpului epoch in variabila now .


    printf("It is %d\n\n\n", now);
}

void time_2(void)
{
    time_t now;

    time(&now);
    printf("It is now %s\n", ctime(&now));
}
