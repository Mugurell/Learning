#include <stdio.h>

int main(void)
{
    const char* keywords[] = {
        "do",
        "for",
        "if",
        "registeringchioszch",
        "return",
        "while",
        NULL //The NULL lets functions that search the table detect
        //the end of the table without knowing its size in advance
        //ex: for( kwp = keywords; *kwp != NULL; kwp++ )
    };

    printf("\nSize of the pointer array is %lu", sizeof(keywords));
    printf("\nSize of the first element of the ptr array is %lu",
           sizeof(keywords[0]));
    printf("\nIf we divide the 2 => there are %lu elements in the array.",
           (sizeof(keywords)) / (sizeof(keywords[0])));
    puts("\n");

    return 0;
}
