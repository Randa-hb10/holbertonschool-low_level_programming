#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* main - Entry point 
*
* Description: ' the program print all single digit numbers '
* Return: Always 0 (success)
*/
int main(void)
{
	int c = '0';

	while (c <= '9')
	{
		printf("%c", c);
		c++;
	}
	printf("\n");
	return(0);
} 

