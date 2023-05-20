#include "main.h"
/**
 * _getenv - gives the value of a variable
 * @var_name: name of the variable
 * Return: pointer to the value
 */

char *_getenv(char *var_name)
{
	char *value = NULL;
	int i, n = _strlen(var_name);

	for (i = 0 ; environ[i] != NULL ; i++)
	{
		if (_strncmp(var_name, environ[i], n) == 0)
			value = environ[i] + n + 1;
	}
	return (value);
}
