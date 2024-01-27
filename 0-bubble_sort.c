#include "sort.h"

/**
 * swap_values - Swap two integers in the array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_values(int *a, int *b)
{
	int tmp_holder;

	tmp_holder = *a;
	*a = *b;
	*b = tmp_holder;
}

/**
 * bubble_sort - Function sorts an array of integers in ascending order.
 * @array: An array of ints to be sort.
 * @size: Size of the array.
 *
 * Description: Prints the array after every swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, len = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (j = 0; j < len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_values(array + j, array + j + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		len--;
	}
}
