/* Write a function that reads a list of integers from the standard input
** and returns the values in a dynamically allocated array. The end of 
** the input list is determined by watching for EOF. The first number in 
** the array should be a count of how many values the array contains. 
** This number is followed by the values. 
*/

#include <stdio.h>
#include <stdlib.h>

void mine(void);
void his(void);

#define MAX 100

int main(void)
{
	his();
    return 0;
}

void mine(void)
{
    int array[100];
    int y, x = 0;

    puts("Enter some numbers separated by whitespaces:");

    while (scanf("%d", &array[x++]) == 1)
        ;

    int* ptr = malloc(x - 1 * sizeof(int));

    if (ptr != NULL) {
        ptr[0] = x - 1;
        for (y = 1; y < x; y++)
            ptr[y] = array[y - 1];
    }

    puts("Your numbers, in a dynamic allocated int array would be..");
    printf("%d: ", ptr[0]);
    x = 1;
    while (x < y) {
        printf("%d, ", ptr[x++]);
    }
    puts("\n");
}

void his(void)
{
    int* array;
    int size;
    int value;
    int count;

    size = MAX;
    array = malloc(size + 1 * sizeof(int));
    /* size+1 <=> space for the first element, the count of numbers */
    if (array == NULL) {
        printf("ERROR: Not enough memory!");
        return;
    }

    puts("Enter some numbers separated by whitespaces:");

    while (scanf("%d", &value) == 1) {
        count += 1;

        if (count > size) {
            size += MAX;
            array = realloc(array, size + 1 * sizeof(int));
            if (array == NULL) {
                printf("ERROR: Not enough memory!");
       			return;
            }
        }
        array[count] = value;
    }
    if (count < size) {
        array = realloc(array, count+1 * sizeof(int));
    	if(array == NULL) {
            printf("ERROR: Not enough memory!");
            return;
            }
    }
    array[0] = count;

    puts("Your numbers, in a dynamic allocated int array would be..");
    printf("%d: ", array[0]);
    value = 1;
    while (value <= count) {
        printf("%d, ", array[value++]);
    }
    puts("\n");
}