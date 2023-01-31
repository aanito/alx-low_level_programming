#include "search_algos.h"
/**
 * interpolation_search -  a function that searches for a value
 * in a sorted array of integers using the Interpolation search algorithm
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
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, high = size - 1, low = 0, count = size;

	if (array == NULL || size == 0)
		return (-1);
	while (count--)
	{
		pos = low + (((double)(high - low) /
					(array[high] - array[low])) * (value - array[low]));
		if (pos > high)
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			break;
		}
		printf("Value checked array[%lu] = [%u]\n", pos, array[pos]);
		if (pos < size && array[pos] == value)
			return (pos);
		low = pos + 1;
	}
	return (-1);
}
