#include "sort.h"

/**
 * swap - Swap two integers.
 * @a: Integer 1.
 * @b: Integer 2.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using selection sort.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 */

void selection_sort(int *array, size_t size)
{
	int *current_min;
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		current_min = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *current_min)
				current_min = array + j;
		}

		if ((array + i) != current_min)
		{
			swap(array + i, current_min);
			print_array(array, size);
		}
	}
}
