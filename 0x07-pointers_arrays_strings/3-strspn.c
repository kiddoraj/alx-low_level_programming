#include "main.h"
/**
 *_strspn - gets the length of a prefix substring
 *
 *@s: string
 *@accept:string to match 
 *
 *Return: Returns the number of bytes in the initial segment of s
 *which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int b = 0;
	char *c = accept;

	while (*s++)
	{
		while (*accept++)
			if (*(s - 1) == *(accept - 1))
			{
				b++;
				break;
			}
		if (!(*accept--))
				break;
		accept = c;
	}
	return (b);
}
