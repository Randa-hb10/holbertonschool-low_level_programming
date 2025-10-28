#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find the square root of
 *
 * Return: the natural square root, or -1 if no natural square root exists
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (_sqrt_helper(n, 0));
}
/**
 * _sqrt_helper - helps to find the natural square root using recursion
 * @n: the number
 * @i: the current candidate number being tested
 *
 * Return: the natural square root or -1 if not found
 */
int _sqrt_helper(int n, int i)
{
if (i * i > n)
return (-1);
if (i * i == n)
return (i);
return (_sqrt_helper(n, i + 1));
}
