#include "shell.h"
/**
 * my_printf - simple printf
 * @format: ..
 * Return: ..
 */
int my_printf(const char *format, ...)
{
	va_list args;
	int chars_written = 0;
	char buffer[256];

	va_start(args, format);
	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
			{
				int value = va_arg(args, int);
				int num_digits = getNumDigits(value);

				sprintf(buffer, "%d", value);
				int num_chars = write(1, buffer, num_digits);

				chars_written += num_chars;
			} else if (format[i] == 's')
			{
				char *str = va_arg(args, char*);
				int length = 0;

				while (str[length] != '\0')
					length++;
				int num_chars = write(1, str, length);

				chars_written += num_chars;
			} else
			{}
		} else
		{
			int num_chars = write(1, &format[i], 1);

			chars_written += num_chars;
		}
	}
	va_end(args);
	return (chars_written);
}
