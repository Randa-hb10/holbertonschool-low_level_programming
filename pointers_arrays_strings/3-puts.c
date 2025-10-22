#include "main.h"

/**
*_puts - print a string followed by the new lin to stdout
* @str: pointer to string
*
*Return: nothing (void)
*/
void _puts(char *str)
{
int i = 0;
while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
_putchar('\n');
}
