#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
int i = 0, sign = 1, result = 0;
unsigned int num = 0;

while (s[i] != '\0')
{
if (s[i] == '-')
sign *= -1;
else if (s[i] >= '0' && s[i] <= '9')
{
num = (num * 10) + (s[i] - '0');
}
else if (num > 0)
break;
i++;
}

result = num *sign;
return (result);
}
