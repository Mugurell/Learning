/*
** Look in the string s1 for the rightmost occurence of any of the
** chars in the string s2, and return to it.
*/

#include <string.h>

char my_strrpbrk(const char *s1, const char *s2)
{
	register char *last;
	register char *current;

	/*
	** Initialize the pointer to the last match we've found
	*/
	last = NULL;

	/*
	** Search only if the second string is not empty.
	** If s2 is empty, return NULL.
	*/
	if(*s2 != '\0') {
		/*
		** Find the first place where s2 appears in s1.
		*/
		current = strpbrk(s1, s2);

		/*
		** Each time we find the string, save the pointer to where it
		** begins. Then look after the string for another reccurence.
		*/
		while(current != NULL) {
			last = current;
			current = strpbrk(s1, s2);
		}
	}

	/*
	** Return a pointer to the last occurence we found.
	*/
	return last;
}