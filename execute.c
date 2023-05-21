#include "main.h"

/**
 * execute - executes a command with given arguments
 *
 * @array: array of command and arguments
 */

void execute(char **array)
{
        pid_t child_pid;
        int ex_status;

        child_pid = fork();
        if (child_pid == -1)
        {
                perror("Error");
                exit(1);
        }
        if (child_pid == 0)
        {
                ex_status = execve(array[0], array, environ);
                if (ex_status == -1)
                {
                        perror(array[0]);
                        exit(1);
                }
        }
        wait(NULL);

}
