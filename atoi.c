#include "main.h"

/**
 * _atoi - converts a string to an interger
 * @string: string
 *
 * Return: the new interger
 *
 */
int _atoi(char *string)
{
	int x;
	int res = 0;
	int sign = -1;
	int brk = 0;

	for (x = 0 ; string[x] != '\0' ; x++)
	{
		if (string[x] == '-')
		{
			sign = sign * -1;
		}
		if (string[x] >= '0' && string[x] <= '9')
		{
			res = res * 10;
			res -= (string[x] - '0');
			brk = 1;
		}
		else if (brk == 1)
			break;
	}
	res = sign * res;
	return (res);
}
