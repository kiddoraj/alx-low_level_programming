#include "main.h"
#include<stdlib.h>

/**
 *create_array - creates an array
 *@size: size of array
 *@c:character
 *
 *Return:null = 0
 */
char *create_array(unsigned int size, char c)
{
	char *p;
	unsigned int i;

	if (size == 0)
		return (0);
	p = (char *) malloc(sizeof(char) * size);

	if (p == NULL)
		return (0);
	while (i < size)
	{
		*(p + 1) = c;
		i++;
	}
	*(p + 1) = '\0';
	return (p);
}
