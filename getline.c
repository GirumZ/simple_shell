#include "main.h"

/**
 * signal_handler - handles the SIGNIT signal
 * @signal: return value of a signal
 * Return: void
 *
 */
void signal_handler(int signal)
{
	(void) signal;
	write(1, "\n$ ", 3);
	kill(getpid(), SIGCONT);
}

/**
 * take_command - takes command from the user
 *
 * Return: pointer to the command it reads
 *
 */
char *take_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t true_read;

	signal(SIGINT, signal_handler);

	true_read = getline(&line, &len, stdin);

	if (true_read == -1)
	{
		free(line);
		write(1, "\n", 1);
		exit(0);
	}
	if (strcmp(line, "\n") == 0)
	{
		free(line);
		shell_loop();
	}
	return (line);
}
