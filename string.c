#include "shell.h"
/**
 * strngcspn - calculates length of str
 * @str: ..
 * @reject: ..
 * Return: ..
 */
size_t strngcspn(const char *str, const char *reject)
{
	const char *s1 = str;
	size_t count = 0;

	while (*s1)
	{
		const char *s2 = reject;

		while (*s2)
		{
			if (*s1 == *s2)
				return (count);
			s2++;
		}
		s1++;
		count++;
	}

	return (count);
}
/**
 *strngcmp - compares two strings
 * @str1: ..
 * @str2:..
 * Return:..
 */

int strngcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
/**
 * strlength - ...
 *@str: ...
 * Return: ...
 */
size_t strlength(const char *str)
{
	const char *p = str;

	while (*p != '\0')
	{
		p++;
	}
	return (p - str);
}
/**
 * strngcpy - ...
 * @dest: ..
 * @src: ...
 * Return: ...
 */
char *strngcpy(char *dest, const char *src)
{
	char *p = dest;

	while (*src != '\0')
	{
		*p++ = *src++;
	}
	*p = '\0';
	return (dest);
}
/**
 *strngdup - ...
 *@str: ..
 *Return: ...
 */
char *strngdup(const char *str)
{
	size_t len;
	char *dup;

	if (str == NULL)
	{
		return (NULL);
	}
	len = strlength(str) + 1;
	dup = malloc(len);

	if (dup != NULL)
	{
		strngcpy(dup, str);
	}
	return (dup);
}
