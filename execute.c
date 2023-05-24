#include "main.h"
/**
 * execute - executes a command with given arguments
 * @cmd: the command
 * @array: array of command and arguments
 */

void execute(char *cmd, char **array)
{
	char **env = environ;
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(cmd, array, env) == -1)
			perror(cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
