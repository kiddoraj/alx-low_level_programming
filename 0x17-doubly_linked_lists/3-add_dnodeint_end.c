#include "lists.h"
/**
 * add_dnodeint_end - adds a new node at the end of a list
 * @head: head of the list
 * @n: value of the element
 *
 * Return: the address of the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h;
	dlistint_t *temp;

	temp = malloc(sizeof(dlistint_t));
	if (temp == NULL)
		return (NULL);

	temp->n = n;
	temp->next = NULL;

	h = *head;

	if (h != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = temp;
	}
	else
	{
		*head = temp;
	}

	temp->prev = h;

	return (temp);
}
