#include <stdio.h>

#define PRINT	 puts("Hello\n");

int main(void)
{

	/*
	** If the end of the statement ends with a defined
	** You don't need to put a semicolon!!!!
	**
	** If you do, the result will be two statement: the "#define"d one,
	** followed by an empty statement. 
	** Having two statements will cause problems in contexts where only
	** one statement is allowed, for example: 
 	**
	**		if( ... )
	**			DEBUG_PRINT;
	**		else
	**			..
	*/

	
	PRINT;;;;;;;;;

	puts("This is a test");;;;;;;;;;;;;;;;;;;

	return 0;
}