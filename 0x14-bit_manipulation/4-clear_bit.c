#include "main.h"
#include<stdio.h>
/**
 *clear_bit - set the value of abit to 0 at a given index
 *@n:pointer
 *@index:index
 *
 *Return:1 if it worked,else -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;
	unsigned int hold;

	if (index > 64)
		return (-1);

	hold = index;

	for (i = 1; hold > 0; i *= 2, hold--)
		;
	if ((*n >> index) & 1)
		*n -= i;
	return (1);
}
