#include "main.h"

/**
 * tokenizer - tokenizes a string and save them in an array
 * @string: string to be tokenized
 * Return: created array
 *
 */
char **tokenizer(char *string)
{
	char *str1 = NULL, *str2 = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int size = 1, sign = 0, i;

	str1 = _strdup(string);
	if (str1 == NULL)
		return (NULL);
	str2 = str1;

	while (*str2)
	{
		if (_strchr(delim, *str2) != NULL && sign == 0)
		{
			size++;
			sign = 1;
		}
		else if (_strchr(delim, *str2) == NULL && sign == 1)
			sign = 0;
		str2++;
	}

	tokens = malloc(sizeof(char *) * (size + 1));
	token = strtok(str1, delim);

	for (i = 0; token != NULL ; i++)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	tokens[i] = '\0';
	free(str1);
	return (tokens);
}
