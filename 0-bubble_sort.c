#include "sort.h"

/**
 * swap - swap teo integers
 * @s: pointer to first value
 * @b: pointer to second val
 * buble_sort - performs bubble sort
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	i = 0;
	swapped = false;

	do {
		swapped = false;
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[1 + j])
			{
				swap(array + j, array + j + 1);
				print_array(array, size);
				swapped = true;
			}
		}
		i++;
	} while (swapped);
}
