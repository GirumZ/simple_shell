#include "main.h"
/**
 * signal_handler - handls the ctrl + c signal
 * @signal: the signal
 * Return: void
 */

void signal_handler(int signal)
{
	(void) signal;
	write(STDOUT_FILENO, "\n$ ", 3);
	kill(getpid(), SIGCONT);
}

/**
 * take_command - takes a command from the user
 * Return: the command read
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
		if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (_strcmp(line, "\n") == 0)
	{
		free(line);
		shell_loop();
	}
	if (line[true_read] == '\n')
		line[true_read] = '\0';
	return (line);

}
