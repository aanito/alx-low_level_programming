#ifndef _SEARCH_ALGOS_H_
#define _SEARCH_ALGOS_H_

#include <math.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index
 * @next: Pointer
 *
 * Description: singly linked list
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int _binary_search(int *array, size_t left, size_t right, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary_recursive(int *array, size_t left, size_t right, int value);
int advanced_binary(int *array, size_t size, int value);

#endif
