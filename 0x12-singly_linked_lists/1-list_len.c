#include "lists.h"
#include<stdlib.h>
/**
 *list_len - returns the number of elements in a linked list
 *@h:pointer
 *
 *Return:number of elements
 */
size_t list_len(const list_t *h)
{
	size_t s = 0;

	while (h)
	{
		s++;

		h = h->next;
	}
	return (s);
}
