#include "search_algos.h"

typedef unsigned int size_t;

/**
 * linear_search - Searches for a value in an array of integers using
 * the Linear search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where the value is located, or -1 if not found.
 */
int linear_search(int *array, size_t size, int value) {
    if (array == NULL) {
        return -1;
    }

    size_t i;
    for (i = 0; i < size; i++) {
        printf("Value checked array[%u] = %d\n", i, array[i]);
        if (array[i] == value) {
            return i;
        }
    }

    return -1;
}

