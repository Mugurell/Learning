#include <stdio.h>

int main()
{
    char c;

    puts("Available packages:");
    puts("A - Transportation, Hotel and Meals.");
    puts("B - Transportation and Hotel.");
    puts("C - Transportation only.");

    printf("\nSelect your package: \n\n");
    c = getchar();

    switch(c)
    {
    case 'A':
    case 'a':
        puts ("You get Meals and");
    case 'B':
    case 'b':
        puts ("You get Hotel and");
    case 'C':
    case 'c':
        puts ("You get transportation.");
        break;
    case 'F':
        case 'f':
        puts("Fuck you bah!");
    default:
        puts ("You don't get nuthin!");
    }
    return 0;
}
