#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: destination string
 * @src: source string
 * @n: maximum number of bytes to use from src
 *
 * Description: This function appends at most n bytes from src to the
 * end of dest, overwriting the terminating null byte (\0) at the end
 * of dest, and then adds a terminating null byte.
 * Return: pointer to resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
int i = 0;
int j = 0;

/* Find the end of dest */
while (dest[i] != '\0')
i++;

/* Append up to n bytes from src */
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}

dest[i] = '\0';

return (dest);
}
