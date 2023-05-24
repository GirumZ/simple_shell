#include "main.h"

/**
 * shell_loop - enters into a loop
 *
 */
void shell_loop(void)
{
	char *command;
	char **array;

	while (1)
	{
		if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
			write(STDOUT_FILENO, "$ ", 2);

		command = take_command();

		array = tokenizer(command);

		if (array == NULL || *array == NULL || **array == '\0')
		{
			iterate_free(array);
			continue;
		}

		if (cmd_handle(array) == 0)
			continue;
	}
}

