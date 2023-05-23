#include "main.h"

/**
 * execute - executes a command with given arguments
 *
 * @array: array of command and arguments
 */

void execute(char **array)
{
	char **env = environ;
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(array[0], array, env) == -1)
		{
			perror(array[0]);
		}
	}
	else
	{
		wait(&status);
		free(array);
	}

}
