#include<unistd.h>
/**
 * _putchar - writes the character c to stdout
 *
 * @c: the character to print
 *
 * Return: on success 1
 * -1 on error
 *  and errno is set approximately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
