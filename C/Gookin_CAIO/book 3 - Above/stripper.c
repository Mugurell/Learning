#include <stdio.h>
#include <ctype.h>


int main()
{
    char sent[200];
    int x=0;

    printf("Enter here, the normal, boring, plain sentence : %c\n" , 31);
    gets(sent);

while(sent[x])
{
    if(isalnum(sent[x]))
        sent[x] = tolower(sent[x]);
    else
        sent[x] = '1';
    x++;
}



    printf("This is the stripped version : %c\n" , 25);
    puts(sent);
    return 0;


}
