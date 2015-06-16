#include <stdio.h>

int main(void)
{
	char longest[1000];
	char line[1000];
	int c;		//use int to store getchar() because EOF >  char
	int x = 0; 		//counts the characters
	int l = 0;		//store the highest count of chars

	while((c = getchar()) != EOF) {
		line[x++] = c;
		if(c == '\n') {
			if(x > l) {
				line[x] = '\0';
				l = x;
				x = 0;
				while(longest[x] = line[x])
					x++;
				printf("\n\tLongest line now is:\n\t %s\n", line);
				x = 0;		//start a new line from 0
			}
			else {
				printf("\n\tLongest line still is:\n\t %s\n", longest);
				x = 0; 		//start a new line from 0
			}
		}

	}
	return 0;
}