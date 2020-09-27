#include "holberton.h"

/**
 * _strlen - Calculates the length of a string
 * @s: string to be treated
 *
 * Return: length of @s
 **/
int _strlen(const char *s)
{
	int l = 0;

	while (*(s + l) != '\0')
		l++;
	return (l);
}
