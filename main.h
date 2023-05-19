#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

extern char **environ;

char **tokenizer(char *string, char *delim);
char *take_command(void);
void shell_loop(void);
void eof_handler(void);
void sigint_handler(int signal);


#endif /* MAIN_H */
