#include "holberton.h"

/**
 * print - It prints to stdout.
 * @str: string.
 *
 * Return: len
 */
int print(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		write(1, &str[i], 1);
	return (i);
}
