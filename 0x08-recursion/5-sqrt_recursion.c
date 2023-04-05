#include "main.h"
/**
 *_sqrt_recursion - returns the natural sqrt of a number
 *n: number
 *
 *Return: -1 if n does not have a natural sqrt
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (ntrl_sqrt(n, 1));
}

/**
 *ntrl_sqrt - natural sqrt
 *@n:number
 *@i:number
 *Return:sqrt
 */
int ntrl_sqrt(int n, int i)
{
	if (n < 0)
	{
		return (-1);
	}
	if ((i * i) > n)
	{
		return (-1);
	}
	if (i * i == n)
	{
		return (1);
	}
	return (ntrl_sqrt(n, i + 1));
}
