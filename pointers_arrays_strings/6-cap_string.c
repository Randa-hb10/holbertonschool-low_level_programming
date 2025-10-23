#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to be modified
 *
 * Description: This function capitalizes the first character of each
 * word in the string. Words are separated by space, tabulation,
 * new line, ,, ;, ., !, ?, ", (, ), {, and }.
 * Return: pointer to the resulting string
 */
char *cap_string(char *str)
{
int i = 0;

if (str[i] >= 'a' && str[i] <= 'z')
str[i] = str[i] - ('a' - 'A');

i = 1;
while (str[i] != '\0')
{
if ((str[i - 1] == ' '  || str[i - 1] == '\t' || str[i - 1] == '\n' ||
str[i - 1] == ','  || str[i - 1] == ';' || str[i - 1] == '.' ||
str[i - 1] == '!'  || str[i - 1] == '?' || str[i - 1] == '"' ||
str[i - 1] == '('  || str[i - 1] == ')' || str[i - 1] == '{' ||
str[i - 1] == '}') &&
str[i] >= 'a' && str[i] <= 'z')
{
str[i] = str[i] - ('a' - 'A');
}
i++;
}

return (str);
}
