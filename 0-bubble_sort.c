#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: None.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, unsorted_size = size;
	int temp, swapped = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < unsorted_size; j++)
		{
			if (array[j - 1] > array[j])
			{
				swapped = 1;
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;

		swapped = 0;
		unsorted_size--;
	}
}
