#include "sort.h"

/**
 * _swap - swaps arrays, highs and lows
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

	partition(array, 0, (int)size - 1, size);
}

/**
 * partition - lomuto scheme
 * @array: array
 * @high: high
 * @low: low
 * @size: size
 *
 * Return: i on success
 */

void partition(int *array, int high, int low, size_t size)
{
	int j = low;
	int i;
	int pivot = array[high];

	if (low >= high)
		return;

	for(i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
			j++;
		}
	}
	if (j != high)
	{
		swap(array, high, j);
		print_array(array, size);
	}
	partition(array, low, j - 1, size);
	partition(array, j + 1, high, size);

}
