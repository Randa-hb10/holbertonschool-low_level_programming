#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: string to encode
 *
 * Description: Letters a/A->4, e/E->3, o/O->0, t/T->7, l/L->1.
 * You can only use one if and two loops.
 * Return: pointer to the resulting string
 */
char *leet(char *str)
{
int i, j;
char letters[] = "aAeEoOtTlL";
char numbers[] = "4433007711";

for (i = 0; str[i] != '\0'; i++)
{
for (j = 0; letters[j] != '\0'; j++)
{
if (str[i] == letters[j])
{
str[i] = numbers[j];
break;
}
}
}

return (str);
}
