#include "function_pointers.h"
#include<stdlib.h>
/**
 *array_iterator - executes a function given as a parameter
 *@array:array
 *@size:size of array
 *@action:pointer
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (!array || !action)
		return;
	for (i = 0; i < size; i++)
		action(array[i]);
}
