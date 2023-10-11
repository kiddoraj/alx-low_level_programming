#include "search_algos.h"

/**
 * rec_search - Recursive binary search helper function.
 */
int rec_search(int *array, size_t left, size_t right, int value)
{
    if (left <= right)
    {
        size_t mid = left + (right - left) / 2;

        printf("Searching in array: %d", array[left]);
        for (size_t i = left + 1; i <= right; i++)
            printf(", %d", array[i]);
        printf("\n");

        if (array[mid] == value)
        {
            if (mid == left || array[mid - 1] != value)
                return mid;
            else
                return rec_search(array, left, mid - 1, value);
        }
        else if (array[mid] < value)
            return rec_search(array, mid + 1, right, value);
        else
            return rec_search(array, left, mid - 1, value);
    }
    
    return -1;
}

/**
 * advanced_binary - Searches for the first occurrence of a value in a
 *                  sorted array of integers using binary search.
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    return rec_search(array, 0, size - 1, value);
}
