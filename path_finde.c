#include "main.h"
/**
 * true_path - looks for  the full path of a command
 * @cmd: the command
 * Return: the full path if found and NULL if not
 */

char *true_path(char *cmd)
{
	char *name = "PATH", *path = NULL, *full_path = NULL;
	char **paths = NULL;
	int i, size = 0;

	path = _getenv(name);
	paths = tokenizer(path);

	for (i = 0 ; paths[i] != NULL ; i++)
	{
		size = (_strlen(paths[i]) + _strlen(cmd) + 2);
		full_path = malloc(sizeof(char) * size);
		_strcpy(full_path, paths[i]);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);
		if (full_path[size - 1] == '\n')
			full_path[size - 1] = '\0';
		
		if (access(full_path, X_OK) == 0)
		{
			free(paths);
			return (full_path);
		}
		free(full_path);
	}
	free(paths);
	return (NULL);
}
