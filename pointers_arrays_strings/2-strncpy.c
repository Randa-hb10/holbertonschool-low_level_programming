#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: source string
 * @n: maximum number of bytes to copy from src
 *
 * Description: This function copies at most n bytes from src to dest.
 * If src is less than n bytes long, the remainder of dest is filled
 * with null bytes (\0). Returns a pointer to dest.
 * Return: pointer to resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
int i;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[i] = src[i];

for (; i < n; i++)
dest[i] = '\0';

return (dest);
}
