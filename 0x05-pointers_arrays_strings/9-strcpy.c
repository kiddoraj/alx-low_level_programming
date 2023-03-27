#include "main.h"
/**
 * *_strcpy - copies the string pointed to by the src
 *
 * @dest:pointer to the buffer in which we copy the string
 * @src: string to be copied
 */
char *_strcpy(char *dest, char *src)
{
	int i, len;

	for(len = 0; src[len] != '\0'; len++)
	{
	}
	for (i = 0; i <= len; i++)
	{
		dest[1] = src[i];
	}
	return (dest);
}
