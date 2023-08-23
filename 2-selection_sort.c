#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * @array: array to sort
 * @size: size
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp = 0, flag = 0, current = 0;

	while (i < (size - 1))
	{
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (flag == 0)
			{
				if (array[i] > array[j])
				{
					flag = 1;
					temp = array[j];
					current = j;
				}
			}
			else if (temp > array[j])
			{
				temp = array[j];
				current = j;
			}
		}
		if (flag == 1)
		{
			array[current] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		i++;
	}
}
