#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: the number of arguments passed to the function
 *
 * Return: the sum of all parameters, or 0 if n == 0
 */
int sum_them_all(const unsigned int n, ...)
{
va_list args;       /* variable list to hold the arguments */
unsigned int i;     /* counter for the loop */
int sum = 0;        /* variable to store the total sum */

/* if there are no arguments, return 0 */
if (n == 0)
return (0);

/* initialize the argument list */
va_start(args, n);

/* iterate through all arguments */
for (i = 0; i < n; i++)
{
sum += va_arg(args, int);  /* get next int and add it to sum */
}

/* clean up the argument list */
va_end(args);

/* return the final sum */
return (sum);
}
