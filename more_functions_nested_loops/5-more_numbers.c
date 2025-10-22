#include "main.h"

/**
 * more_numbers - prints 10 times the numbers from 0 to 14
 *
 * Return: void
 */
void more_numbers(void)
{
int i, j;

for (i = 0; i < 10; i++) /* loop 10 times */
{
for (j = 0; j <= 14; j++) /* print numbers 0 to 14 */
{
if (j > 9)
_putchar((j / 10) + '0'); /* print tens digit */
_putchar((j % 10) + '0');     /* print ones digit */
}
_putchar('\n'); /* new line after each row */
}
}
