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

/**
 * struct node - struct
 * @dir: directory
 * @next: pointer
 */
typedef struct node
{
	char *dir;
	struct node *next;
} list_t;

extern char **environ;

char **tokenizer(char *string, char *delim);
char *take_command(void);
void shell_loop(void);
void eof_handler(void);
void sigint_handler(int signal);
char *_getenv(char *var_name);
char *true_path(char *cmd);
list_t *path_list(void);
list_t *add_node_end(list_t **head, const char *str);
void execute(char **array);
int cmd_handl(char **array);
void free_list(list_t *head);
size_t print_list(const list_t *h);

/* helper functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, size_t n);
#endif /* MAIN_H */
