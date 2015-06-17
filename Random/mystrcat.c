char* mystrcat(char* dest, char* src)
{
    while (*dest)
        dest++;
    while (*dest++ = *src++)
        ;
    return --dest;
}

/*
What have we done here? At very little extra cost we're returning 
a pointer to the end of the new, longer string. 
That way the code that calls this function can decide to 
append further without rescanning the string:

char bigString[1000];     /* I never know how much to allocate... 
char *p = bigString;
bigString[0] = '\0';
p = mystrcat(p,"John, ");
p = mystrcat(p,"Paul, ");
p = mystrcat(p,"George, ");
p = mystrcat(p,"Joel ");

This is, of course, linear in performance, not n-squared, so it doesn't
suffer from degradation when you have a lot of stuff to concatenate.
*/