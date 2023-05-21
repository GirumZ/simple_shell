#include "main.h"

/**
 * shell_loop - enters into a loop
 *
 */
void shell_loop(void)
{
        char *command;
        char **array;
        int cmd_result;


        while (1)
        {
                write(1, "$ ", 2);

                command = take_command();

                array = tokenizer(command, " \n\0");

                cmd_result = cmd_handl(array);


                free(command);
                free(array);

                if (cmd_result == 1)
                        break;
        }
}
