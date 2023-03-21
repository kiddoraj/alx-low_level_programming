#include "main.h"
/**
 * print_alphabet_x10 -prints 10 times the alphabet
 *
 * Return: Its void
 */
void print_alphabet_x10(void)
{
	char c = 'a';
	int i = 0;

	while (i < 10)
	{
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		_putchar('\n');
		i++;
	}
}
