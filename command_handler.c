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
        char *value;

        if (strcmp(array[0], "exit") == 0)
        return (1);
        else if (strcmp(array[0], "env") == 0)
        {
                print_environment();
                return (0);
        }
        else if (strcmp(array[0], "getenv") == 0)
        {
                if (array[1] != NULL)
                {
                        value = _getenv(array[1]);
                        if (value != NULL)
                        {
                                 write(1, value, _strlen(value));
                                 write(1, "\n", 1);
                        }
                }
                return (0);;

        }
        else if (strcmp(array[0], "ls") == 0)
        {
                full_cmd = "/bin/ls";
		array[0] = full_cmd;
                execute(array);
                return (0);
        }
        else if (strcmp(array[0], "pwd") == 0)
        {
                full_cmd = "/bin/pwd";
                array[0] = full_cmd;
                execute(array);
                return (0);
        }
        else

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
