/***********http://www.sudo.ws/todd/papers/strlcpy.html*************
*********************************************************************
The strlcpy() and strlcat() functions provide a consistent, 
unambiguous API to help the programmer write more bullet-proof code. 
** First and foremost, both strlcpy() and strlcat() guarantee to 
NUL-terminate the destination string for all strings where the 
given size is non-zero. 
** Secondly, both functions take the full size of the destination string 
as a size parameter. In most cases this value is easily computed at 
compile time using the sizeof operator. 
** Finally, neither strlcpy() nor strlcat() zero-fill their destination
strings (other than the compulsatory NUL to terminate the string).

The strlcpy() and strlcat() functions return the total length of the 
string they tried to create. 
** For strlcpy() that is simply the length of the source;
** For strlcat() that means the length of the destination 
(before concatenation) plus the length of the source. 

To check for truncation, the programmer need only verify that 
the return value is less than the size parameter. 
** Thus, if truncation has occurred, the number of bytes needed to store 
the entire string is now known and the programmer may allocate more 
space and re-copy the strings if he or she wishes. 
** If no truncation occurred, the programmer now has the length of the 
resulting string. This is useful since it is common practice to build 
a string with strncpy() and strncat() and then to find the length 
of the result using strlen(). With strlcpy() and strlcat() the final 
strlen() is no longer necessary. 
*********************************************************************/

/* 
** Example of implementation

		len = strlcpy(path, homedir, sizeof path);
			if (len >= sizeof path)
				return (ENAMETOOLONG);
		len = strlcat(path, "/", sizeof path);
			if (len >= sizeof path)
				return (ENAMETOOLONG);
		len = strlcat(path, ".foorc", sizeof path);
			if (len >= sizeof path)
				return (ENAMETOOLONG);
*/


/*************************************************************
** Apparently you must include the below for them to work..:
**************************************************************/



#ifndef HAVE_STRLCAT
/*************************************************************
 * '_cups_strlcat()' - Safely concatenate two strings.
***************************************************************/

size_t							/* O - Length of string */
strlcat(char *dst,        		/* O - Destination string */
        const char *src,		/* I - Source string */
        size_t     size)		/* I - Size of destination string buffer */
{
  size_t    srclen;         	/* Length of source string */
  size_t    dstlen;         	/* Length of destination string */


/*
* Figure out how much room is left...
*/
  dstlen = strlen(dst);
  size   -= dstlen + 1;

  if (!size)
    return (dstlen);        	/* No room, return immediately... */

/*
* Figure out how much room is needed...
*/
  srclen = strlen(src);

/*
* Copy the appropriate amount...
*/
  if (srclen > size)
    srclen = size;

  memcpy(dst + dstlen, src, srclen);
  dst[dstlen + srclen] = '\0';

  return (dstlen + srclen);
}
#endif /* !HAVE_STRLCAT */




#ifndef HAVE_STRLCPY
/***************************************************************
 * '_cups_strlcpy()' - Safely copy two strings.
****************************************************************/

size_t                  		/* O - Length of string */
strlcpy(char *dst,        		/* O - Destination string */
        const char *src,		/* I - Source string */
        size_t size)     		/* I - Size of destination string buffer */
{
  size_t srclen;         		/* Length of source string */

/*
* Figure out how much room is needed...
*/
  size --;
  srclen = strlen(src);

/*
* Copy the appropriate amount...
*/
  if (srclen > size)
    srclen = size;

  memcpy(dst, src, srclen);
  dst[srclen] = '\0';

  return (srclen);
}
#endif /* !HAVE_STRLCPY */