#include "main.h"
/**
 * print_number - prints an integer
 * @n: integer
 *
 */
void print_number(int n)
{
	unsigned int mbr;

	if (n < 0)
	{
		mbr = -n;
		_putchar('-');
	}
	else 
	{
		mbr = n;
	}
	if (mbr / 10)
		print_number(mbr / 10);
	_putchar((mbr % 10) + '0');
}
