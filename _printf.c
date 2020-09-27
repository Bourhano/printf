#include "holberton.h"
#include<strings.h>

/**
 * get_dir_count - Returns the number of directives in the format string
 * @format: the formatting string
 *
 * Return: number of directives
 **/
int get_dir_count(const char *format)
{
	int n = 0;
	const char *exFormat = format;

	while (*exFormat != 0)
	{
		if (exFormat[1] == 0)
			;
		else if (*exFormat == '%')
		{
			if (exFormat == format)
				n++;
			else if (*(exFormat - 1) != '%')
				n++;
		}
		exFormat++;
	}
	return (n);
}


/**
 * _printf - Prints the input string based on the formatting
 * @format: the formatting string
 *
 * Return: number of characters printed
 **/
int _printf(const char *format, ...)
{
        va_list valist, list;
	int n, length = 0, l, i;
	const char *exFormat = format;
	char directive, *toPrint, *output, c;

        n = get_dir_count(format);
	va_start(valist, format);
	if (n == 0)
	{
		print(format);
		return (_strlen(format));
	}
	else
	{
		va_copy(list, valist);
		exFormat = format;
		while (*exFormat != 0)
		{
			if (exFormat[1] == 0)
				;
			else if (*exFormat == '%')
			{
				exFormat++;
				directive = *exFormat;
				switch (directive)
				{
				case '%':
					length++;
					break;
				case 'c':
					va_arg(list, int);
					length++;
					break;
				case 's':
					toPrint = va_arg(list, char *);
					l = _strlen(toPrint);
					length += l;
					break;
				}
			}
			exFormat++;
		}
		va_end(list);
		l = _strlen(format);
		length = length + l - 2 * n + 1;
		output = malloc(length);
		exFormat = format;
		i = 0;
		while (*exFormat != 0)
		{
			if (*exFormat != '%')
				output[i++] = *exFormat;
			else
			{
				exFormat++;
				directive = *exFormat;
				switch (directive)
				{
				case '%':
					output[i++] = '%';
					break;
				case 'c':
				        c = va_arg(valist, int);
					output[i++] = c;
					break;
				case 's':
					toPrint = va_arg(valist, char *);
					while (*toPrint != 0)
						output[i++] = *toPrint++;
					break;
				}
			}
			exFormat++;
		}
		va_end(valist);
		output[i] = 0;
		print(output);
		return (length);
	}
}
