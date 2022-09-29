#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - Print all elements from a list
 * @h: pointer to the star of a linked list
 *
 * Return: number of elements
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}
