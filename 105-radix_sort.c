#include "sort.h"

/* function prototypes */
void radix_counting_sort(int *array, size_t size, int exp);


/**
 * get_max - A utility function to get maximum
 * @arr: value in arr[]
 * @n: number of array element's
 * Return: max number
 */
int get_max(int arr[], int n)
{
	int max = arr[0];
	int i;

	for (i = 1; i < n; i++)
	{
		if (arr[i] > max)
		max = arr[i];
	}
	return (max);
}


/**
 * radix_sort - sorts an array of integers in
 * ascending order using the Radix
 *
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, (int)size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		radix_counting_sort(array, size, exp);
		print_array(array, size);
	}
}

/**
 * radix_counting_sort - sorts an array of integers
 * in ascending order using the
 * Counting sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 * @exp: exponent
 */
void radix_counting_sort(int *array, size_t size, int exp)
{
	int *output, *freq, i;

	freq = malloc(sizeof(int) * 10);
	if (freq == NULL)
		return;

	for (i = 0; i < 10; i++)
		freq[i] = 0;

	for (i = 0; i < (int)size; i++)
		freq[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		freq[i] += freq[i - 1];

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(freq);
		return;
	}

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[freq[(array[i] / exp) % 10] - 1] = array[i];
		freq[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(freq);
	free(output);
}
