#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: list of integer elements
 * @size: length of array
 */

void shell_sort(int *array, size_t size)
{
	size_t h, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (h <= size / 3)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
		{
			tmp = array[i];
			j = i;

			while (j >= h && array[j - h] > tmp)
			{
				array[j] = array[j - h];
				j -= h;
			}

			array[j] = tmp;
		}

		h = h / 3;
		print_array(array, size);
	}
}
