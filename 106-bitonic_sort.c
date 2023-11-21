#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two values in either ascending or descending order.
 * @arr: Array.
 * @index1: Index of the first item.
 * @index2: Index of the second item.
 * @ascending: 1 for ascending order, 0 for descending order.
 */
void swap(int arr[], int index1, int index2, int ascending)
{
	int temp;

	if (ascending == (arr[index1] > arr[index2]))
	{
		temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
}

/**
 * merge - Sorts bitonic sequences recursively in both ascending and descending orders.
 * @arr: Array.
 * @low: First element index.
 * @numElements: Number of elements.
 * @ascending: 1 for ascending order, 0 for descending order.
 */
void merge(int arr[], int low, int numElements, int ascending)
{
	int mid, i;

	if (numElements > 1)
	{
		mid = numElements / 2;
		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, ascending);
		merge(arr, low, mid, ascending);
		merge(arr, low + mid, mid, ascending);
	}
}

/**
 * bitonic_sort_recursive - Bitonic sort algorithm implementation.
 * @arr: Array.
 * @low: Index of the first element.
 * @numElements: Number of elements to sort.
 * @ascending: 1 for ascending order, 0 for descending order.
 * @size: Length of the array.
 */
void bitonic_sort_recursive(int arr[], int low, int numElements, int ascending, int size)
{
	int mid;

	if (numElements > 1)
	{
		if (ascending >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", numElements, size);
			print_array(&arr[low], numElements);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", numElements, size);
			print_array(&arr[low], numElements);
		}
		mid = numElements / 2;
		bitonic_sort_recursive(arr, low, mid, 1, size);
		bitonic_sort_recursive(arr, low + mid, mid, 0, size);
		merge(arr, low, numElements, ascending);
		if (ascending <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", numElements, size);
			print_array(&arr[low], numElements);
		}
		if (ascending >= 1)
		{
			printf("Result [%i/%i] (UP):\n", numElements, size);
			print_array(&arr[low], numElements);
		}
	}
}

/**
 * bitonic_sort - Initiates the Bitonic sort algorithm.
 * @array: Array to be sorted.
 * @size: Length of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	int ascending = 1;

	if (!array || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, ascending, size);
}
