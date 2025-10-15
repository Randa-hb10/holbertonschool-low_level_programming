#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'the program prints the alphabets in lowercase using puchar'
 *
 * Return: Always 0 (Success)
 */

int main(void)
{

	char c = 'a';
	char cc = 'A';

	while (c <= 'z')
	{
		putchar(c);
		c++;
	}

	while (cc <= 'Z')
	{
		putchar(cc);
		cc++;
	}

	putchar ('\n');

	return (0);

}

