#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy_data - Copies data from one buffer to another.
 *
 * @src: Source buffer.
 * @dst: Destination buffer.
 * @size: Size of buffers.
 *
 * Return: No Return.
 */
void copy_data(int *src, int *dst, int size)
{
	int i;

	for (i = 0; i < size; i++)
		dst[i] = src[i];
}

/**
 * merge - Merges two sets of data in ascending order.
 *
 * @array: First set of data.
 * @buffer: Second set of data.
 * @min_left: Lower range of the first set of data.
 * @max_left: Upper range of the first set of data.
 * @min_right: Lower range of the second set of data.
 * @max_right: Upper range of the second set of data.
 *
 * Return: No Return.
 */
void merge(int *array, int *buffer, int min_left, int max_left, int min_right, int max_right)
{
	int i = min_left, j = min_right, k = min_left;

	while (i <= max_left || j <= max_right)
	{
		if (i <= max_left && j <= max_right)
		{
			if (buffer[i] <= buffer[j])
				array[k++] = buffer[i++];
			else
				array[k++] = buffer[j++];
		}
		else if (i > max_left && j <= max_right)
			array[k++] = buffer[j++];
		else
			array[k++] = buffer[i++];
	}
}

/**
 * print_range - Prints an array in a given range.
 *
 * @array: Array of data to be printed.
 * @start: Start of the range.
 * @end: End of the range.
 *
 * Return: No Return.
 */
void print_range(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * split_merge - Recursive function to split data into a merge tree.
 *
 * @array: Array of data to be split.
 * @buffer: Auxiliary array of data for merging.
 * @min: Min range of data in array.
 * @max: Max range of data in array.
 * @size: Size of total data.
 *
 * Return: No Return.
 */
void split_merge(int *array, int *buffer, int min, int max, int size)
{
	int mid, temp_max, min_left, max_left, min_right, max_right;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	temp_max = max;
	max = mid - 1;

	min_left = min;
	max_left = max;

	split_merge(array, buffer, min, max, size);

	min = mid;
	max = temp_max;

	min_right = min;
	max_right = max;

	split_merge(array, buffer, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");
	print_range(array, min_left, max_left);
	printf("[right]: ");
	print_range(array, min_right, max_right);

	merge(array, buffer, min_left, max_left, min_right, max_right);
	copy_data(array, buffer, size);

	printf("[Done]: ");
	print_range(array, min_left, max_right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 *
 * @array: Array of data to be sorted.
 * @size: Size of data.
 *
 * Return: No Return.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	copy_data(array, buffer, size);

	split_merge(array, buffer, 0, size - 1, size);

	free(buffer);
}
