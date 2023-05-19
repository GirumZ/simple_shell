#include "main.h"

/**
 * add_node_end - adds a new node at the end of a list
 * @str: string element of a list
 * @head:
 *
 * Return: new list
 *
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *current = *head;
	unsigned int i;

	for (i = 0 ; str[i] != '\0' ; i++)
		;
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->dir = strdup(str);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (new);
}
