#include <stdio.h>

typedef char byte;      //! byte e aliasul lui char
typedef int word;       //! word e aliasul lui int

/*!Note that using typedef in ODDVAR.C doesn’t redefine char and int; those
two types still exist and could be used. But byte and word can also be used
as alternatives.
*/

word main()
{
    byte a;

    for(a=65; a<90; a++)
    putchar(a);
    putchar('\n');

    exit (6435);
}
