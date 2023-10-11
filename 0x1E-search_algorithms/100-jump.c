#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers using
 * the Jump search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int jump_search(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
        return -1; // Array is NULL or empty, return -1
    }

    int step = (int)sqrt(size);
    int prev = 0;
    int index = 0;

    printf("Value checked array[0] = [%d]\n", array[0]);

    while (array[index] < value) {
        printf("Value checked array[%d] = [%d]\n", index, array[index]);
        prev = index;
        index += step;

        if (index >= (int)size) {
            break;
        }
    }

    printf("Value found between indexes [%d] and [%d]\n", prev, index);

    for (int i = prev; i <= index && i < (int)size; i++) {
        printf("Value checked array[%d] = [%d]\n", i, array[i]);
        if (array[i] == value) {
            return i;
        }
    }

    return -1; // Value not found in the array
}
