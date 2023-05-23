#include "main.h"
/**
 * _exit - exits the shell
 * @array: array of command and arguments
 */

void exit_shell(char **array)
{
	free(array);
	exit(0);
}
