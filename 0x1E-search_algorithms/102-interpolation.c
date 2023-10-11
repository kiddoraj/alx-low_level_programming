#include "search_algos.h"
/**
 * interpolation_search - Searches for a value in a sorted array of integers
 * using the Interpolation search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int interpolation_search(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
        return -1; // Array is NULL or empty, return -1
    }

    size_t low = 0;
    size_t high = size - 1;
    size_t pos;
    double f;

    while (low <= high && value >= array[low] && value <= array[high]) {
        f = (double)(high - low) / (array[high] - array[low]) * (value - array[low]);
        pos = (size_t)(low + f);
        printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

        if (array[pos] == value) {
            return (int)pos; // Value found, return its index
        }

        if (array[pos] < value) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1; // Value not found in the array
}
