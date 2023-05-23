#include "main.h"

/**
 * tokenizer - tokenizes a string and save them in an array
 * @string: string to be tokenized
 * @delim: the delimeter
 *
 * Return: created array
 *
 */
char **tokenizer(char *string, char *delim)
{
        char *token;
        size_t i, size = 0;
        char **tokens;

        for (i = 0 ; string[i] != '\0' ; i++)
        {
                if (string[i] == delim[0])
                        size++;
        }
        token = strtok(string, delim);

        tokens = malloc(sizeof(char *) * (size + 2));
        if (tokens == NULL)
        {
                perror("Error");
                exit(1);
        }
        for (i = 0 ; token != NULL ; i++)
        {
                tokens[i] = token;
                token = strtok(NULL, delim);
        }
        tokens[i] = NULL;
        return (tokens);
}
