#include "main.h"

/**
 * shell_loop - enters into a loop
 * @av: vector of arguments for main function
 */
void shell_loop(char **av)
{
	char *command;
	char **array;

	while (1)
	{
		if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
			write(STDOUT_FILENO, "$ ", 2);

		command = take_command(av);

		array = tokenizer(command);

		if (array == NULL || *array == NULL || **array == '\0')
		{
			iterate_free(array);
			continue;
		}

		if (cmd_handle(array, av) == 0)
			continue;
	}
}

