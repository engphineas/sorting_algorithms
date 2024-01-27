#include "sort.h"

/**
 * swap_values - Swap two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void swap_values(int *a, int *b)
{
	int tmp_holder;

	tmp_holder = *a;
	*a = *b;
	*b = tmp_holder;
}

/**
 * selection_sort - Function to sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t j, k;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min = array + j;
		for (k = j + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;

		if ((array + j) != min)
		{
			swap_values(array + j, min);
			print_array(array, size);
		}
	}
}
