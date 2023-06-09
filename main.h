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
#include <sys/stat.h>



extern char **environ;

char **tokenizer(char *string);
char *take_command(char **av);
void shell_loop(char **av);
void sigint_handler(int signal);
char *_getenv(char *var_name);
char *true_path(char *cmd);
void execute(char *cmd, char **array);
int cmd_handle(char **array, char **av);
void exit_shell(char **array);
void _env(char **array);
int for_builtin(char **array);
int mysetenv(int argc, char **argv);
int myunsetenv(int argc, char **argv);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int builtin_cd(int argc, char **argv);

/* helper functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, size_t n);
char *_strchr(char *str, char c);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _atoi(char *string);
void iterate_free(char **array);

#endif /* MAIN_H */
