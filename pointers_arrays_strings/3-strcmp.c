#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Description: This function compares the strings s1 and s2.
 * It returns an integer less than, equal to, or greater than zero
 * if s1 is found, respectively, to be less than, to match, or be
 * greater than s2.
 * Return: difference between the first unmatched characters or 0
 */
int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
i++;
}

return (s1[i] - s2[i]);
}
