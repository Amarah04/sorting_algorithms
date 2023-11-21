#include "sort.h"

/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, i, size, size);

	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - Adjusts the heap to maintain the heap property.
 * @array: The array to be heapified.
 * @idx: The index to start heapifying from.
 * @idx2: The size of the heap.
 * @size: The size of the array.
 */
void heapify(int *array, int idx, int idx2, size_t size)
{
	int max = idx2;
	int left = 2 * idx2 + 1;
	int right = 2 * idx2 + 2;
	int temp;

	if (left < idx && array[left] > array[max])
		max = left;
	if (right < idx && array[right] > array[max])
		max = right;
	if (max != idx2)
	{
		temp = array[idx2];
		array[idx2] = array[max];
		array[max] = temp;
		print_array(array, size);
		heapify(array, idx, max, size);
	}
}
