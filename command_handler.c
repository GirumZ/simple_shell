#include "main.h"
/**
 * cmd_handl - handles the command accordingly
 * @array: array of the command
 *
 * Return: void
 */

int cmd_handl(char **array)
{
	struct stat st;
	char *full_cmd;

	if (stat(array[0], &st) == 0 && access(array[0], X_OK) == 0)
	{
		execute(array);
		return (0);
	}
	full_cmd = true_path(array[0]);
	if (full_cmd != NULL)
	{
		array[0] = full_cmd;
		execute(array);
		return (0);
	}
	perror(array[0]);
	return (1);
}
