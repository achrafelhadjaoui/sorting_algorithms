#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int min, tmp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				k = j;
			}
		}
		if (array[i] != min)
		{
			tmp = array[i];
			array[i] = min;
			array[k] = tmp;
			print_array(array, size);
		}
	}
}
