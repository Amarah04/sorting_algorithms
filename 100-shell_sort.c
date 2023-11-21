#include "sort.h"

/**
  * shell_sort - Implements the Shell sort algorithm with Knuth sequence.
  * @array: The array to be sorted.
  * @size: The size of the array.
  */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	gap = 1;
	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
