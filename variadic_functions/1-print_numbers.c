#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - prints numbers, followed by a new line
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 *
 * Description: prints all numbers given as arguments,
 * separated by the separator string (if not NULL).
 * A newline is printed at the end.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
va_list args;        /* variable list for the arguments */
unsigned int i;      /* counter for looping */

/* initialize the argument list */
va_start(args, n);

for (i = 0; i < n; i++)
{
/* print the next integer */
printf("%d", va_arg(args, int));

/* print the separator only if it's not NULL and not the last number */
if (separator != NULL && i < n - 1)
printf("%s", separator);
}

/* print a newline at the end */
printf("\n");

 /* clean up */
va_end(args);
}
