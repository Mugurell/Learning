/* Write a function called my_strcat that is similar to strcat 
but will not overflow the destination array. 
The result must be a true string. 
*/

#include <stdio.h>
#include <string.h>
#include <strlcpy.h>

void my_strcat(char *first, const char *second);

int main(void)
{
	char first[100];
	char second[100];

	puts("Say something nice!");
	fgets(first, 100, stdin);
	puts("\nNow somethig to append to what you previously said?");
	fgets(second, 100, stdin);
	printf("sizeof first is %lu\n", sizeof first);
	puts("\nCool!\nSo we've got..");

	my_strcat(first, second);

	return 0;
}

void my_strcat(char *first, const char *second)
{
	char dest[100] = {""};

	printf("Dest now is %s", dest);

	size_t len = strlcat(dest, first, sizeof dest);
	if(len >= sizeof dest) {
		puts("ETOOBIG");
		return;
	}

	len = strlcat(dest, second, sizeof dest);
		if(len >= sizeof dest) {
			puts("Error: Too big!");
			return;
		}
	puts(dest);
}
