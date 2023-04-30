#include "lists.h"
#include<stdio.h>
/**
 *print_listint - prints all elements of a list
 *@h:pointer
 *
 *Return:nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h= h->next;
	}
	return (num);
}
