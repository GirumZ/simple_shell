#include "main.h"
/**
 * _env - prints the environment variable
 * Reeturn: void
 */

void _env(char **array)
{
	int i;
	char **env = environ;

	(void) array;

	for (i = 0 ; env[i] != NULL ; i++)
	{
		write(1, env[i], _strlen(env[i]));
		write(1, "\n", 1);
	}
}