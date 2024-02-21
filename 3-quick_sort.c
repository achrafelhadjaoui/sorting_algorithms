#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: the given array
 * @x: index of first integer
 * @y: index of second integer
 * @size: size of the array
 */

void swap(int *a, int x, int y, int size)
{
	int tmp;

	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
	print_array(a, size);
}

/**
 * partition - partitions the array for quicksort
 * @a: pointer to array
 * @start: starting index of the partition
 * @end: ending index of the partition
 * @size: size of the array
 *
 * Return: index of the pivot element
 */

int partition(int *a, int start, int end, int size)
{
	int pivot, wall, i;

	pivot = a[end];
	wall = start;
	for (i = start; i < end; i++)
	{
		if (a[i] < pivot)
		{
			if (i != wall)
				swap(a, i, wall, size);
			wall++;
		}
	}
	if (end != wall && a[end] != a[wall])
	{
		swap(a, end, wall, size);
	}
	return (wall);
}

/**
 * helper_sort - recursive helper function for quicksort
 * @a: pointer to array
 * @start: starting index of the partition
 * @end: ending index of the partition
 * @size: size of the array
 */

void helper_sort(int *a, int start, int end, int size)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = partition(a, start, end, size);
		helper_sort(a, start, pivot_index - 1, size);
		helper_sort(a, pivot_index + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: input array
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	helper_sort(array, 0, size - 1, size);
}
