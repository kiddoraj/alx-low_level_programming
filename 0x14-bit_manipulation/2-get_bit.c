#include "main.h"
#include<stdio.h>
/**
 *get_bit - get thr value of a bit at a given index
 *@n:int to evaluate
 *@index:index
 *
 *Return:value of abit at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int hold;

	if (index > 64)
		return (-1);
	
	hold = n >> index;

	return (hold & 1);
}
