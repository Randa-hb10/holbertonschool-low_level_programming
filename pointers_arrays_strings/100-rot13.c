#include "main.h"

/**
* rot13 - Encodes a string using ROT13
* @s: The string to encode
*
* Return: Pointer to the encoded string
*
* Description: This function takes a string and encodes it using the
* ROT13 substitution cipher, which replaces each letter with the
* letter 13 positions ahead in the alphabet.
*/

char *rot13(char *s)
{
int i, j;
char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char rot13_letters[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

for (i = 0; s[i]; i++)
{
for (j = 0; letters[j]; j++)
{
if (s[i] == letters[j])
{
s[i] = rot13_letters[j];
break;
}
}
}
return (s);
}
