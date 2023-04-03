#include "main.h"
/**
 *
 *_memset - fills memory with a constant byte
 *@s:memory area to be filled
 *@b:char to copy
 *@n:number of times to copy

 *Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int m;

	for (m = 0; m < n; m++)
	{
		s[m] = b;
	}
	return (s);
}
