#include "main.h"

/**
 * shell_loop - enters into a loop
 *
 */
void shell_loop(void)
{
	char *command;
	char **array;
	int ex_status, status;
	pid_t child_pid;

	while (1)
	{
		write(1, "$ ", 2);

		command = take_command();

		array = tokenizer(command, " \n\0");

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			exit(1);
		}
		if (child_pid == 0)
		{
			ex_status = execve(array[0], array, environ);
			if (ex_status == -1)
			{
				perror(array[0]);
				break;
			}
		}
		wait(&status);
		free(command);
		free(array);
	}
}
