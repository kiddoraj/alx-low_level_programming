#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created sorted hash table,
 *         or NULL if something went wrong.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *shash_table;
    unsigned long int i;

    if (size == 0)
        return NULL;

    shash_table = malloc(sizeof(shash_table_t));
    if (shash_table == NULL)
        return NULL;

    shash_table->size = size;
    shash_table->array = malloc(sizeof(shash_node_t *) * size);
    if (shash_table->array == NULL)
    {
        free(shash_table);
        return NULL;
    }

    shash_table->shead = NULL;
    shash_table->stail = NULL;

    for (i = 0; i < size; i++)
        shash_table->array[i] = NULL;

    return shash_table;
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table to add/update the key/value to
 * @key: The key
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 * The key/value pair is inserted in the sorted list at the right place
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node, *temp, *prev = NULL;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return 0;

    index = hash_djb2((unsigned char *)key) % ht->size;

    /* Check if key already exists, update its value */
    temp = ht->array[index];
    while (temp != NULL)
    {
        int cmp_result = strcmp(temp->key, key);
        if (cmp_result == 0)
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
        else if (cmp_result > 0)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    /* Key doesn't exist, create a new node and insert it at the right place in the sorted list */
    new_node = malloc(sizeof(shash_node_t));
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

    new_node->next = temp;
    if (prev != NULL)
        prev->next = new_node;
    else
        ht->array[index] = new_node;

    if (temp == NULL)
        ht->stail = new_node;

    /* Update the sorted list head if necessary */
    if (prev == NULL)
        ht->shead = new_node;

    return 1;
}

/**
 * shash_table_get - Retrieves a value associated with a key from the sorted hash table
 * @ht: The sorted hash table to look into
 * @key: The key you are looking for
 *
 * Return: The value associated with the element,
 *         or NULL if the key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    shash_node_t *temp;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return NULL;

    index = hash_djb2((unsigned char *)key) % ht->size;

    temp = ht->array[index];
    while (temp != NULL)
    {
        int cmp_result = strcmp(temp->key, key);
        if (cmp_result == 0)
            return temp->value;
        else if (cmp_result > 0)
            break;
        temp = temp->next;
    }

    return NULL;
}

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: The sorted hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node = ht->shead;
    int is_first = 1;

    printf("{");
    while (node != NULL)
    {
        if (!is_first)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        is_first = 0;
        node = node->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order
 * @ht: The sorted hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node = ht->stail;
    int is_first = 1;

    printf("{");
    while (node != NULL)
    {
        if (!is_first)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        is_first = 0;
        node = node->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *temp;
    unsigned long int i;

    if (ht == NULL)
        return;

    /* Free each node in the sorted hash table */
    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            temp = node;
            node = node->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }

    /* Free the array and the sorted hash table */
    free(ht->array);
    free(ht);
}
