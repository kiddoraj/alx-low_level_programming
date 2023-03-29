#include "main.h"
/**
 * reverse_array - reverses the content of an array
 * @a:array to revesre
 * @n: number of elements of the array
 */
void reverse_array( int *a, int n)
{
	int i, j;

	i = 0;

	while (i < n)
	{
		n--;
		j = a[i];
		a[i] = a[n];
		a[n] = j;
		i++;
	}
}
