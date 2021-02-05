#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - swap two cases
 * @a: integer
 * @b: integer
 */

void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
/**
 * heapify - heapify array
 * @array: array
 * @n: integer
 * @i: integer
 * @size: size of array
 */
void heapify(int *array, int n, int i, size_t size)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && array[l] > array[largest])
		largest = l;
	if (r < n && array[r] > array[largest])
		largest = r;
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, n, largest, size);
	}
}

/**
 * heap_sort - heap sort array
 * @array: array of intgers
 * @size: size_t of array
 */

void heap_sort(int *array, size_t size)
{
	int i, j;

	if (!array || size <= 1)
		return;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, (int)size, i, size);
	for (i = (int)size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		for (j = i; j >= 0; j--)
		{
		heapify(array, i, j, size);
	  }
		swap(&array[0], &array[i]);
		print_array(array, size);
	}
}
