#include "main.h"

/**
 * for_builtin - Checks if a command is a built-in command and executes it
 * @array: Array of command and arguments
 * Return: 0 if the command is a built-in
 * and executed successfully, 1 otherwise
 */
int for_builtin(char **array)
{
	if (_strcmp(array[0], "env") == 0)
	{
		_env(array);
		return (0);
	}
	else if (_strcmp(array[0], "exit") == 0)
	{
		exit_shell(array);
		return (0);
	}
	else if (_strcmp(array[0], "setenv") == 0)
	{
		return (mysetenv(3, array));
	}
	else if (_strcmp(array[0], "unsetenv") == 0)
	{
		return (myunsetenv(2, array));
	}

	return (1);
}
