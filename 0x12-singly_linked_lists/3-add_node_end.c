#include "lists.h"
#include<string.h>
#include<stdlib.h>
/**
 *add_node_end - add a new node at thr end of a linked list
 *@head:pointer
 *@str:string
 *
 *Return:address of thr new element
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *temp = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	new = malloc(sizeof(list_t));

	if(!new)
		return (NULL);

	new->str = strdup(str);
	new->len = len;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;

		return (new);
	}
	while (temp->next)
		temp = temp->next;
	return (new);
}
