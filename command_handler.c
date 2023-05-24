#include "main.h"
/**
 * cmd_handle - handles the diffferent types of commands
 * @array: array of command and arguments
 * Return: 0 on success and 1 on failure
 */

int cmd_handle(char **array)
{
	struct stat st;
	char *full_cmd;

	if (for_builtin(array) == 0)
	{
		iterate_free(array);
		return (0);
	}
	if (stat(array[0], &st) == 0 && access(array[0], X_OK) == 0)
	{
		execute(array[0], array);
		iterate_free(array);
		return (0);
	}
	full_cmd = true_path(array[0]);

	if (full_cmd != NULL)
	{
		execute(full_cmd, array);
		free(full_cmd);
		iterate_free(array);
		return (0);
	}
	perror(array[0]);
	free(full_cmd);
	iterate_free(array);
	return (0);
}
