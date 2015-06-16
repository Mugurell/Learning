#include <stdio.h>

void print_ledger(int x)
{
#ifdef OPTION_LONG
#	define 	OK 	1
	print_ledger_long(x)
#endif

#ifdef OPTION_DETAILED
#	define 	OK 	1
	print_ledger_detailed(int)
#endif

#ifndef OK
	print_ledger_default(int)
}
