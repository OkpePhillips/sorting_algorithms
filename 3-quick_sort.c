#include "sort.h"

/**
 * swap - Swaps two elements in an array
 *
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 *
 * @array: The array to be partitioned
 * @low: Index of the low end of the partition
 * @high: Index of the high end of the partition
 *
 * Return: The pivot index
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high)
{
	int pivot;
	ssize_t i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, high + 1);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, high + 1);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick sort
 *
 * @array: The array to be sorted
 * @low: Index of the low end of the partition
 * @high: Index of the high end of the partition
 *
 * Return: Nothing
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t pivot;

		pivot = lomuto_partition(array, low, high);
		quick_sort_recursive(array, low, pivot - 1);
		quick_sort_recursive(array, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme)
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}
