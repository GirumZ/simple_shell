#include "main.h"
/**
 * for_builtin - checks for built in command and select function
 * @array: array of command
 * Return: 0 on success and 1 in failure
 */

int for_builtin(char **array)
{


	if (_strcmp(array[0], "env") == 0)
	{
		_env(array);
		return (0);
	}
	if (_strcmp(array[0], "exit") == 0)
	{
		exit_shell(array);
		return (0);
	}
	return (1);
}
