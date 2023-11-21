#include "sort.h"

/**
  * quick_sort - Implements the quicksort algorithm.
  * @array: The array to be sorted.
  * @size: The size of the array.
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}

/**
  * recursive_quick_sort - Recursively sorts the array using quicksort.
  * @arr: The array to be sorted.
  * @left: The leftmost index.
  * @right: The rightmost index.
  * @size: The full size of the array.
  */
void recursive_quick_sort(int *arr, int left, int right, size_t size)
{
	int pivot_index;

	if (left < right)
	{
		pivot_index = partition(arr, left, right, size);
		recursive_quick_sort(arr, left, pivot_index - 1, size);
		recursive_quick_sort(arr, pivot_index + 1, right, size);
	}
}

/**
  * partition - Partitions the array for quicksort.
  * @arr: The array to be partitioned.
  * @left: The leftmost index.
  * @right: The rightmost index.
  * @size: The full size of the array.
  * Return: The pivot index.
  */
int partition(int *arr, int left, int right, size_t size)
{
	int i, j, pivot, temp;

	pivot = arr[right];
	i = left;

	for (j = left; j < right; j++)
	{
		if (arr[j] < pivot)
		{
			if (i != j)
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] != arr[right])
	{
		temp = arr[i];
		arr[i] = arr[right];
		arr[right] = temp;
		print_array(arr, size);
	}

	return i;
}
