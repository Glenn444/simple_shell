#include "shell.h"
/**
 * getNumDigits - counts the number of digits
 * @num: ..
 * Return: count
 */
int getNumDigits(int num)
{
	int count = 0;

	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
