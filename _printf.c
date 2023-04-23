#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: the format string.
 * Return: the number of characters printed
 *
 */

int _printf(const char *format, ...)
{
	va_list args;

	int count = 0, i = 0;
	char *s;
	char c;

	va_start(args, format);

	if (format == NULL)
	{
		retrun (-1);
	}
	if (format)
	{
		while (format[i] != '\0')
		{
			if (format[i] == '%')
			{
				i++;

				switch (format[i])
				{
					case 'c':
						c = va_arg(args, int);
						putchar(c);
						count++;
						break;
					case 's':
						s = va_arg(args, char*);
						if (s == NULL)
						{
							s = "(null)";
						}
						while (*s != '\0')
						{
							putchar(*s);
							count++;
							s++;
						}
						break;
					case '%':
						putchar('%');
						break;
					default:
						putchar('%');
						count += 2;
						break;
				}
			}
			else
			{
				putchar(format[i]);
				count++;
			}
			i++;

		}
	}
	va_end(args);

	return(count);
}
