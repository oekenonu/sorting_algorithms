#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t i, j;
    int interval = 1;
    int temp;

    if (array == NULL || size < 2)
        return;

    while (interval < (int)size / 3)
        interval = interval * 3 + 1;

    while (interval > 0)
    {
        for (i = interval; i < size; i++)
        {
            temp = array[i];
            j = i;

            while (j >= (size_t)interval && array[j - interval] > temp)
            {
                array[j] = array[j - interval];
                j -= interval;
            }
            array[j] = temp;
        }
        print_array(array, size);
        interval /= 3;
    }
}

