#include "search_algos.h"
/**
 * binary_search_e - a function that searches for a value in a
 * sorted array of integers using the Binary search algorithm
 *
 * @array: is a pointer to the first element of the array to search in
 * assume that array will be sorted in ascending order
 *
 * @index: where array pointer is pointing
 *
 * @size:  is the number of elements in array
 *
 * @value:  is the value to search for
 * assume that value won’t appear more than once in array
 *
 * Return: the index where value is located
 * Otherwise -1 if value is not present in array or array is NULL
 */
int binary_search_e(int *array, int index, size_t size, int value)
{
	int left = index, right = (int)size - 1, mid, i;

	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			if (i != right)
				printf("%d, ", array[i]);
			else
				printf("%d\n", array[i]);
		}
		mid = (left + right) / 2;

		if (array[mid] == value)
			return (mid);
		else if (value > array[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
/**
 * exponential_search - a function that searches for a value
 * in a sorted array of integers using the Exponential search algorithm
 * assume that array will be sorted in ascending order
 *
 * @array:  is a pointer to the first element of the array to search in
 *
 * @size: is the number of elements in array
 *
 * @value: is the value to search for
 *
 * Return: the first index where value is located
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, last_index;

	if (array == NULL || size == 0)
		return (-1);
	if (array[0] == value)
		return (0);
	for (i = 1; i < size; i = i * 2)
	{
		if (array[i] < value)
			printf("Value checked array[%lu] = [%u]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		else if (array[i] > value || i * 2 >= size)
		{
			if (i * 2 >= size)
			{
				*array = array[i];
				printf("Value found between indexes [%lu] and [%lu]\n", i, size - 1);
				return (binary_search_e(array, i, size, value));

			}
			else
				*array = array[last_index];
			printf("Value found between indexes [%lu] and [%lu]\n",
					last_index, i - last_index + 2);
			return (binary_search_e(array, last_index, i - last_index + 3, value));
		}
		last_index = i;
	}
	return (-1);
}
