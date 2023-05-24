#include "main.h"

/**
 * exit_shell - exits the shell
 * @array: array of command and arguments
 */

void exit_shell(char **array)
{
	int status;

	if (array[1])
	{
		status = atoi(array[1]);

		if (status >= 0)
		{
			iterate_free(array);
			exit(status);
		}
		perror("Exit");
	}
	iterate_free(array);
	exit(EXIT_SUCCESS);
}
