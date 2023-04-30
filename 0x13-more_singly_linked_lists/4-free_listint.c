#include "lists.h"
#include <stdlib.h>
/**
 *free_listint - frees a linkded loist
 *@head:pointer
 */
void free_listint_t(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
