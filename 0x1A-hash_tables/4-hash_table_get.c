#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key from the hash table
 * @ht: Pointer to the hash table
 * @key: The key you are looking for
 *
 * Return: The value associated with the element, or NULL if the key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *tmp;

    if (ht == NULL || key == NULL || *key == '\0')
        return NULL;

    index = key_index((const unsigned char *)key, ht->size);
    tmp = ht->array[index];

    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
            return tmp->value;
        tmp = tmp->next;
    }

    return NULL;
}
