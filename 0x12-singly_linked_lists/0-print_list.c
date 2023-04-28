#include "lists.h"
#include<stdio.h>
/**
 *print_list - prints the elements of a linked list
 *@h:pointer
 *
 *Return:number of nodes printed
 */
size_t print_list(const list_t *h)
{
	size_t c = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s", h->len, h->str);

		h = h->next;

		c++;
	}
	return (c);
}
