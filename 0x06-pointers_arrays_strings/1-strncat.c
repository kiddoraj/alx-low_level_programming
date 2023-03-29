#include "main.h"
/**
 * *strncat - concatenates two strings
 *
 * @dest: string
 * @src: string
 * @n: number of bytes to concatenate
 *
 * Return: return a pointer to the reulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	i = j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
