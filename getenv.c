#include "main.h"
/**
 * _getenv - gives the value of a variable
 * @var_name: name of the variable
 * Return: pointer to the value
 */

char *_getenv(char *var_name)
{
	char *value = NULL;
	char **env = environ;
	int i, n = _strlen(var_name);

	for (i = 0 ; env[i] != NULL ; i++)
	{
		if (_strncmp(var_name, env[i], n) == 0)
			value = env[i] + n + 1;
	}
	env = environ;
	return (value);
}
