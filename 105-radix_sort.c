#include <stdlib.h>
#include "sort.h"

/**
 * radix_counting_sort - Auxiliary function of Radix sort.
 *
 * @array: Array of data to be sorted.
 * @bucket: Malloc buffer.
 * @size: Size of data.
 * @digit: The current digit being considered.
 *
 * Return: No Return.
 */
void radix_counting_sort(int *array, int **bucket, int size, int digit)
{
	int i, j, bucket_size = 10, num;
	int count[bucket_size] = {0};
	int count_copy[bucket_size] = {0};

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < digit; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		bucket[num][count[num]] = array[i];
		count[num] += 1;
	}

	for (i = 0, j = 0; i < bucket_size; i++)
	{
		while (count[i] > 0)
		{
			array[j] = bucket[i][count_copy[i]];
			count_copy[i] += 1, count[i] -= 1;
			j++;
		}
	}

	print_array(array, size);
}

/**
 * radix_count_sort - Auxiliary function of Radix sort.
 *
 * @array: Array of data to be sorted.
 * @size: Size of data.
 * @digit: The current digit being considered.
 *
 * Return: No Return.
 */
void radix_count_sort(int *array, int size, int digit)
{
	int count[10] = {0};
	int i, j, num, bucket_size = 10, **bucket;

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < digit; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		count[num] += 1;
	}

	if (count[0] == size)
		return;

	bucket = malloc(sizeof(int *) * 10);
	if (!bucket)
		return;

	for (i = 0; i < bucket_size; i++)
		if (count[i] != 0)
			bucket[i] = malloc(sizeof(int) * count[i]);

	radix_counting_sort(array, bucket, size, digit);

	radix_count_sort(array, size, digit + 1);

	for (i = 0; i < bucket_size; i++)
		if (count[i] > 0)
			free(bucket[i]);
	free(bucket);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm.
 *
 * @array: Array of data to be sorted.
 * @size: Size of data.
 *
 * Return: No Return.
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	radix_count_sort(array, size, 1);
}
