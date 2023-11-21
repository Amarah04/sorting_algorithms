#include "sort.h"

/**
 * quick_sort_hoare - Initiates the Hoare partition scheme for quicksort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    sort_partition(array, 0, size - 1, size);
}

/**
 * sort_partition - Implements the Hoare partition scheme for sorting.
 * @arr: Array to be sorted.
 * @left: Leftmost index of the array or subarray.
 * @right: Rightmost index of the array or subarray.
 * @size: Size of the full array.
 */
void sort_partition(int *arr, int left, int right, size_t size)
{
    int pivot;

    if ((right - left) < 2)
        return;
    pivot = hoare_partition(arr, left, right, size);
    sort_partition(arr, left, pivot, size);
    sort_partition(arr, pivot, right, size);
}

/**
 * hoare_partition - Chooses a pivot and performs the Hoare partition scheme.
 * @arr: Array to be sorted.
 * @left: Leftmost index of the array or subarray.
 * @right: Rightmost index of the array or subarray.
 * @size: Size of the full array.
 * Return: The pivot index.
 */
int hoare_partition(int *arr, int left, int right, size_t size)
{
    int i, j, pivot, temp;

    pivot = arr[right];
    i = left;
    j = right;

    while (1)
    {
        do
            i++;
        while (arr[i] < pivot);
        do
            j--;
        while (arr[j] > pivot);

        if (i < j)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            print_array(arr, size);
        }
        else
            return j;
    }
}
