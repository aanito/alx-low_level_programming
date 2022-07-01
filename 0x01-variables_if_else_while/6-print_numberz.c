#include <stdio.h>
/*
 * main - Print all single sigit numbers using the putchar starting from 0,
 * 	only using putchar 
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char num;

	for (num = 0; num < 10; num++)
	{
		putchar((num % 10) + '0');
	}
	{
		putchar('\n');
	}

	return (0);
}
