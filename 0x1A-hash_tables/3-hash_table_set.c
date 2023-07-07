#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table
 * @key: The key of the new element
 * @value: The value of the new element
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node, *tmp;

    if (!ht || !key || !value || !*key)
        return 0;

    index = key_index((unsigned char *)key, ht->size);
    tmp = ht->array[index];

    /* Check if key already exists, update its value */
    while (tmp)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            free(tmp->value);
            tmp->value = strdup(value);
            return 1;
        }
        tmp = tmp->next;
    }

    /* Create a new node and add it at the beginning of the list */
    new_node = malloc(sizeof(hash_node_t));
    if (!new_node)
        return 0;

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return 1;
}
