#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key you are looking for
 *
 * Return: The value associated with the element,
 *         or NULL if the key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    hash_node_t *temp;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return NULL;

    index = hash_djb2((unsigned char *)key) % ht->size;

    temp = ht->array[index];
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
            return temp->value;
        temp = temp->next;
    }

    return NULL;
}
