#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int arr[] = {7, 13, 19, 48, 52, 71, 73, 86, 96, 99};
	size_t n = sizeof(arr) / sizeof(arr[0]);
	size_t m = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);

	printf("second value");
	print_array(arr, m);
	printf("\n");
	bubble_sort(arr, m);
	printf("\n");
	print_array(arr, m);
	return (0);
}
