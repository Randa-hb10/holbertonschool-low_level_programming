#include <stdio.h>

/* this program is to print alphabets in lowercase using putchar */

int main(void)
{

	char c = 'a';

	while (c <= 'z')
	{
		putchar(c);
		c++;
	}

	putchar ('\n');

	return (0);

}

