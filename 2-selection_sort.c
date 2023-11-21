#include "sort.h"

/**
  * selection_sort - Sorts an array using the selection sort algorithm.
  * @array: The array to be sorted.
  * @size: The size of the array.
  */
void selection_sort(int *array, size_t size)
{
	size_t current_index, next_index;
	int current_min, temp, min_index;

	for (current_index = 0; current_index < size; current_index++)
	{
		current_min = array[current_index];

		for (next_index = current_index + 1; next_index < size; next_index++)
		{
			if (current_min > array[next_index])
			{
				current_min = array[next_index];
				min_index = next_index;
			}
		}

		if (current_min != array[current_index])
		{
			temp = array[current_index];
			array[current_index] = current_min;
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
