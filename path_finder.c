#include "main.h"
/**
 * true_path - checks if a path is found for a command
 * @cmd: the command
 * Return: pointer to the full_path is found and NULL if not
 */


/*list_t *path_list(void)*/
char *true_path(char *cmd)
{
	char *name = "PATH";
	char *path = NULL, *full_path = NULL;
	char **paths = NULL;
	int i, size = 0;


	path = _getenv(name);
	paths = tokenizer(path, ":");

	for (i = 0 ; paths[i] != NULL ; i++)
	{
		size = (strlen(paths[i]) + strlen(cmd) + 2);
		full_path = malloc(sizeof(char) * size);
		strcpy(full_path, paths[i]);
		strcat(full_path, "/");
		strcat(full_path, cmd);
		if (full_path[size - 1] != '\n')
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