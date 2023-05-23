#include "main.h"
/**
 * _strcpy - copies a string to another string
 * @dest: string to add on
 * @src: string to be added
 *
 * Return: the added string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
