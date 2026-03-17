#include <stdio.h>
#include <stdarg.h>

void print_int(int args, ...)
{
	va_list ap; /*Pointer to the current argument*/
	va_start(ap, args); /*initialises ap to read arguments after args*/
	int i;
	for (i=0; i < args; i++){
		printf("argument: %i\n", va_arg(ap, int)); /* read the current argument as int, and move ap forward*/
	}
	va_end(ap); /*end, cleanup*/
}




