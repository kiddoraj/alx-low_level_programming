#include "main.h"
#include<stdlib.h>

/**
 *_strdup - copies the string as parameter
 *@str:string
 *
 *Return:NULL if str = NULL
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	i = len = 0;

	if (str == NULL)
		return (NULL);
	while (str[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);
	while ((dup[i] = str[i]) != '\0')
		i++;
	return (dup);
}
