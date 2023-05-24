#include "main.h"
/**
 * true_path - looks for  the full path of a command
 * @cmd: the command
 * Return: the full path if found and NULL if not
 */

char *true_path(char *cmd)
{
	char *name = "PATH", *path = NULL, *path_copy = NULL, *full_path = NULL;
	char **paths = NULL;
	int i, size = 0;

	path = _getenv(name);
	path_copy = _strdup(path);
	paths = tokenizer(path_copy);

	for (i = 0 ; paths[i] != NULL ; i++)
	{
		size = (_strlen(paths[i]) + _strlen(cmd) + 2);
		full_path = malloc(sizeof(char) * size);
		if (full_path == NULL)
			return (NULL);
		_strcpy(full_path, paths[i]);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);
		if (full_path[size - 1] == '\n')
			full_path[size - 1] = '\0';

		if (access(full_path, X_OK) == 0)
		{
			iterate_free(paths);
			return (full_path);
		}
		free(full_path);
	}
	iterate_free(paths);
	return (NULL);
}
