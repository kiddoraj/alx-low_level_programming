#include "main.h"
/**
 *get_endianness - checks endianness
 *
 *Return - 0 if big endian
 */
int get_endianness(void)
{
	int num = 1;

	if (*(char *) &num == 1)
		return (1);
	else
		return (0);
}
