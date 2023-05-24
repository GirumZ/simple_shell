#include "main.h"
/**
 * exit_shell - exits the shell
 * @array: array of command and arguments
 */

void exit_shell(char **array)
{
	iterate_free(array);
	exit(0);
}
