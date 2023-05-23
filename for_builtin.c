#include "main.h"


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

