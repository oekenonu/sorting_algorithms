#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i, j;

	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
    if (array[i + 1] != array[high])
    {
	    swap(&array[i + 1], &array[high]);
	    print_array(array, size);
    }
    return (i + 1);
}

/**
 * quicksort - Sorts an array using Quick sort algorithm
 * @array: Array to be sorted
 * @low: Starting index of the array
 * @high: Ending index of the array
 * @size: Size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
	int pivot_index = lomuto_partition(array, low, high, size);
	quicksort(array, low, pivot_index - 1, size);
	quicksort(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
	    return;

    quicksort(array, 0, size - 1, size);
}
