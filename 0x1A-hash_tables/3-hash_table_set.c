#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table to add/update the key/value to
 * @key: The key
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 * In case of collision, add the new node at the beginning of the list
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new_node, *temp;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return 0;

    index = hash_djb2((unsigned char *)key) % ht->size;

    /* Check if key already exists, update its value */
    temp = ht->array[index];
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            /* Duplicate the new value */
            char *new_value = strdup(value);
            if (new_value == NULL)
                return 0;

            /* Free the old value and update with the new value */
            free(temp->value);
            temp->value = new_value;
            return 1;
        }
        temp = temp->next;
    }

    /* Key doesn't exist, create a new node and add it at the beginning of the list */
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return 0;

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return 0;
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return 0;
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return 1;
}
