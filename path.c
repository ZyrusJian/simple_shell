#include "shell.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list
 * @head: A pointer to the head of the list_t list
 * @str: The string to be added to the list_t list
 *
 * Return: address of the new element, or NULL on failure
 */

list_t *add_node(list_t **head, char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->len = _strlen(str);
	new->next = *head;

	*head = new;
	return (new);
}

/**
 * construct_path - Constructs the PATH
 *
 * Description: Takes the PATH environment variable
 * and puts it into a linked list.
 *
 * Return: A pointer to the linked list.
 */

list_t *construct_path(void)
{
	char *path, *token;
	list_t *head = NULL;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");
	while (token != NULL)
	{
		add_node(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}

/**
 * run_path_cmd - Attempts to run a command by searching the PATH
 * @args: Null terminated argument array
 *
 * Return: 1 if the shell should continue, 0 if it should terminate
 */

int run_path_cmd(char **args)
{
	list_t *path_list, *node;
	char *command;
	char cmd_path[ARG_MAX];

	path_list = construct_path();

	if (path_list == NULL)
		return (1);

	command = args[0];

	node = path_list;
	while (node != NULL)
	{
		_strcpy(cmd_path, node->str);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, command);
		if (access(cmd_path, X_OK) == 0)
		{
			args[0] = cmd_path;
			execute(args);
			return (1);
		}
		node = node->next;
	}
	printf("%s: command not found\n", args[0]);
	return (1);
}
