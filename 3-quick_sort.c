#include "sort.h"

/**
 * swap - swaps arrays, highs and lows
 * @array: array
 * @f: first
 * @s: second
 *
 * Return: void
 */

void swap(int *array, int f, int s)
{
	int temp;

	temp = array[f];
	array[f] = array[s];
	array[s] = temp;
}

/**
 * quick_sort - sorts integers quickly
 * @array: array of integers to sort
 * @size: size
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_help(array, 0, size - 1, size);
}

/**
 * quick_sort_help - helps quick sort
 * @array: array
 * @low: low
 * @high: high
 * @size: size
 *
 * Return: void
 */

void quick_sort_help(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_help(array, low, pivot - 1, size);
		quick_sort_help(array, pivot + 1, high, size);
	}
}

/**
 * partition - lomuto scheme
 * @array: array
 * @high: high
 * @low: low
 * @size: size
 *
 * Return: partitioned array
 */

int partition(int *array, int high, int low, size_t size)
{
	int j = low;
	int i;
	int pivot = array[high];

	for(i = low - 1; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			j++;
			if (array[i] != array[j])
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(array, high, j);
		print_array(array, size);
	}
	return (i + 1);
}
