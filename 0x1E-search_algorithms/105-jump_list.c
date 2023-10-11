#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Searches for a value in a sorted linked list
 *             using the Jump search algorithm.
 *
 * @list: Pointer to the head of the linked list.
 * @size: Number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where the value is located.
 *         If the value is not present in the list or the list is NULL, return NULL.
 *
 * Description: Prints the value each time it is compared in the list.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t jump = sqrt(size);
    listint_t *current = list, *prev = NULL;

    if (list == NULL || size == 0)
        return NULL;

    while (current->next && current->n < value)
    {
        prev = current;
        for (size_t i = 0; i < jump && current->next; i++)
            current = current->next;

        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);

    while (prev && prev->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        prev = prev->next;
    }

    if (prev && prev->n == value)
        return prev;
    else
        return NULL;
}
