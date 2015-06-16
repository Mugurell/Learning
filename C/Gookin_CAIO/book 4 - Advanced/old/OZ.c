#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGHT 40

int main()
{
    struct cast {       //!structura se numeste cast
        char actor[18];
        int age;
        char role[16]
    };
//    struct cast *star ;      //!create structure pointer
                            //! variabila star pentru structura cast
                            //! star.cast e de tipul pointer
    int line;

    typedef struct cast OZ;     //!struct cast e poreclita OZ
    OZ *star;

/*Get memory chunk*/
    star = (struct cast *)malloc(sizeof(struct cast));
    if(star == (char*) NULL)
    {
        puts("OUM");
        return 0;
    }


    strcpy(star->actor, "Judy Garland");
    star->age = 17;
    strcpy(star->role, "Dorothy");
    puts("\t\tWizard of Oz Database\n");

/*draw the table heading*/
    printf("%-16s %-5s %-15s\n",
           "Actor",
           "Age",
           "Role");
    for(line=0; line<LINE_LENGHT; line++)
        printf("*");
    putchar('\n');


/*display the data*/
    printf("%-16s %-5d %-15s\n",
           star->actor,     //! arrow pointer ( -> ) folosit cand variabila unei structuri e de tipul poiinter
           star->age,       //! in mod normal se folosea variabila.strcture_element
           star->role);     //! fata de pointer->structure_element

    return 0;
}

/*!
✦ The structure pointer is created like any structure variable, though it’s prefixed with a * ,
like all pointers:
            struct cast *star;
✦ In Line 20, the star pointer is assigned a chunk of memory equal to the size of the cast
structure:
            star = (struct cast *)malloc(sizeof(struct cast));
First, malloc() is typecast to be of the same variable type as the cast structure. Internally,
malloc() uses sizeof to get the size of the cast structure and set aside that much memory for a new
variable (of the structure type)
✦ Lines 21 through 25 handle the case when memory cannot be allocated.
Honestly, this isn’t necessary for such a small chunk of memory in a demo program. In real life,
however, when you’re allocating space for sockets or other vital things, checking for available
memory IS A MUST.
✦ With the pointer memory allocated, it can be filled with information. Note how the -> thing is
used in lines 27, 28, and 29 to put data into memory via the pointer.
✦ The official name for the -> thing is ARROW POINTER.
(se foloseste doar in cazul asta(de obicei puneai variabila.struct nelement)).
✦ Finally, the -> thing is used in Lines 44 through 46 to display values stored in
the allocated structure.
✦ Beyond using pointers, this technique is really no different than creating a structure variable
and filling it directly. Again, the advantage here is that you can create new structures on the
fly.
*/
