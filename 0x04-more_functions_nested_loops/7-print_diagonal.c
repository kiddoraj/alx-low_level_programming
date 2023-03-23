#include "main.h"
/**
 * print-diagonal - draws a diagonal line on the terminal
 *
 * @n: number of times the character / is printed
 */
void print_diagonal(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int i;

		for (i = 0; i < n; i++)
		{
			_putchar('\$');
			_putchar('\n');
		}
	}
}
