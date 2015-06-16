#include <stdio.h>
#include "cpu_types.h"

cpu_type(void)
{
#if defined 	VAX
	return 	CPU_VAX;
#elif defind 	M68000
	return 	CPU_68000;
#elif defined 	K68020
	return 	CPU_68020;
#elif defined 	I80386
	return 	CPU_80386
#else
	return CPU_UNKNOWN;
#endif
}