#include "main.h"

char *_strcat(char *dest, char *src)
{
	int i, c;

	for (c = 0 ; dest[c] != '\0' ; c++)
		;
	for (i = 0 ; src[i] != '\0' ; i++)
	{
		dest[c + i] = src[i];
	}
	dest[c + i] = '\0';
	return (dest);
}
