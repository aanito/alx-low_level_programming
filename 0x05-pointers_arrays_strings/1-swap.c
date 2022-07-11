#include "main.h"
/**
 * swap_int - Swaps the values of two integers.
 * @x: The first integer to be swapped.
 * @y: The second integer to be swapped.
 */
void swap_int(int *x, int *y)
{
	int var = *x;
	*x = *y;
	*y = var;
}
