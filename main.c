#include "main.h"

/**
 * main - entry point
 * @av: vector of arguments
 * @ac: number of arguments
 *
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	(void) ac;

	shell_loop(av);
	return (0);
}
