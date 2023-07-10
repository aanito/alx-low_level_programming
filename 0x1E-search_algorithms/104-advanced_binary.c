#include "search_algos.h"
/**
 * advanced_binary - a function that searches for a value in a
 * sorted array of integers using the Binary search algorithm
 *
 * @array: is a pointer to the first element of the array to search in
 * assume that array will be sorted in ascending order
 *
 * @size:  is the number of elements in array
 *
 * @value:  is the value to search for
 * assume that value won’t appear more than once in array
 *
 * Return: the index where value is located
 * Otherwise -1 if value is not present in array or array is NULL
 * Iterative solution
int advanced_binary(int *array, size_t size, int value)
{
	int left = 0, right = (int)size - 1, mid, i, my_return;

	if (array == NULL)
		return (-1);
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
		{
			for (i = mid; array[i - 1] == array[mid]; i--)
			{
				my_return = i;
				return (my_return - 1); 
			}
			return (array[mid]);
		}
		else if (value > array[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
*/
int binary(int *array, int value, int low, int right)
{
	int mid, i;

	if (right >= low)
	{
		printf("Searching in array: ");
		for (i = low; i < right; i++)  
		{
			if (i != right) 
				printf("%d, ", array[i]);
			else
				printf("%d\n", array[i]);
		}
		mid = (low + (right - 1)) / 2;
		if (value == array[mid])
			return (mid);
		if (value < array[mid])
			return binary(array, value, low, mid - 1);
		return binary(array, mid + 1, right, value);
	}
	return (-1);
}
int advanced_binary(int *array, size_t size, int value)
{
	int index = binary(array, value, 0, (int)size - 1), my_return, i;

	if (array == NULL || size == 0)
		return (-1);
	for (i = index; array[i - 1] == array[index]; i--) 
	{
		my_return = i;
		return (my_return - 1);
	}
	return (index);

}
