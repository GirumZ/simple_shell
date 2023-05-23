#include "main.h"
/**
 * _strchr - looks for a character in a string
 * @str: the string
 * @c: the character
 *
 * Return: a pointer to the first incounter of the character and NULL
 * if not found
 */

char *_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (!c)
		return (str);
	return (NULL);
}
