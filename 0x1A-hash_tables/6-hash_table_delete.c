#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: Pointer to the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *node, *next_node;

    if (ht == NULL)
        return;

    /* Free each node in the hash table */
    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            next_node = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = next_node;
        }
    }

    /* Free the hash table array */
    free(ht->array);

    /* Free the hash table structure itself */
    free(ht);
}
