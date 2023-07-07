#include "hash_tables.h"

/**
 * hash_table_print - Prints the keys and values of the hash table
 * @ht: Pointer to the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *tmp;
    int first_pair = 1;

    if (ht == NULL)
        return;

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        tmp = ht->array[i];
        while (tmp != NULL)
        {
            if (!first_pair)
                printf(", ");
            printf("'%s': '%s'", tmp->key, tmp->value);
            first_pair = 0;
            tmp = tmp->next;
        }
    }
    printf("}\n");
}
