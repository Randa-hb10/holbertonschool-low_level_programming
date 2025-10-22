#include "main.h"

/**
* _strlen - returns the length of a string
* @s: string to evaluate
*
* Return: length of the string
*/
int _strlen(char *s)
{
int len = 0;

while (s[len] != '\0')
len++;
return (len);
}

/**
* puts_half - prints half of a string, followed by a new line
* @str: string to print
*/
void puts_half(char *str)
{
int len = _strlen(str);
int i;

/* If length is odd, start at (len + 1) / 2 */
if (len % 2 == 0)
i = len / 2;
else
i = (len + 1) / 2;

for (; i < len; i++)
putchar(str[i]);
putchar('\n');
}
