#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 *
 * @list: Pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where the value is located.
 *         If the value is not present in the list or the list is NULL, return NULL.
 *
 * Description: Prints the value each time it is compared in the list.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express, *current;

    if (list == NULL)
        return NULL;

    express = list;
    while (express->next && express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);

        current = express;
        express = express->express;

        if (express == NULL)
            break;
    }

    printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
    
    printf("Value found between indexes [%lu] and [%lu]\n", current->index, express->index);

    while (current->next && current->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        current = current->next;
    }

    if (current->n == value)
        return current;

    return NULL;
}
