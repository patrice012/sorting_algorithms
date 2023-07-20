#include "sort.h"
/**
 * swap - helper fonction used to swap to value
 * @first: first value
 * @second: second value to swap
 */
void swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}


/**
 * bubble_sort -  sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0;
	int swapped = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
			}
			print_array(array, size);
		}
		if (swapped == 0)
			break;
	}
}
