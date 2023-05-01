#include "lists.h"
/**
 *sum_listint - calculates sum of all data in a list
 *@head:first node
 *
 *Return:reulting sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
