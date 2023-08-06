#include "shell.h"

/**
 * free_list - free the list_t list
 * @head: A pointer to the head of the list_t list
 *
 * Return: address of the new element, or NULL on failure
 */

void free_list(list_t *head)
{
	list_t *current = head;
	list_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

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
	{
		free(new);
		return (NULL);
	}

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
 * construct_cmd_path - construct command path
 * @path: path entry from path_list
 * @command: command to be executed
 *
 * Return: allocated string containing the constructed path,
 *	or NULL on failure
 */

char *construct_cmd_path(char *path, char *command)
{
	char *cmd_path;

	cmd_path = malloc(sizeof(char) * (ARG_MAX));
	if (cmd_path == NULL)
		return (NULL);

	strcpy(cmd_path, path);
	strcat(cmd_path, "/");
	strcat(cmd_path, command);

	return (cmd_path);
}

/**
 * run_path_cmd - Attempt to run command by searching PATH
 * @args: Argument array, args[0] is command
 *
 * Return: 1 on success, 0 on failure
 */

int run_path_cmd(char **args)
{
	list_t *path_list = construct_path();
	char *cmd_path, *command = NULL;
	int i = 0;

	while (args[i] != NULL)
	{
		i++;
	}
	command = args[(i - 1)];
	if (command == NULL)
	{
		fprintf(stderr, "%s: Command not found\n", command);
		return (0);
	} /* Handle empty PATH */
	if (!path_list)
	{
		fprintf(stderr, "%s: Command not found\n", args[0]);
		free_list(path_list);
		return (0);
	}
	cmd_path = NULL;
	for (i = 0; path_list; i++) /* Loop through PATH */
	{	/* Check if PATH entry is executable */
		cmd_path = construct_cmd_path(path_list->str, command);
		if (cmd_path != NULL && access(cmd_path, X_OK) == 0)
		{	/* Execute command */
			args[0] = cmd_path;
			execvp(args[0], args);
			perror("Execvp"); /* Print exec error */
			free(cmd_path);
			args[0] = args[0] - (i * (ARG_MAX)); /* Restore arg */
			return (1);
		}
		free(cmd_path);
		path_list = path_list->next;
	}	/* Command not found */
	fprintf(stderr, "%s: Command not found.\n", args[0]);
	free_list(path_list);
	return (0);
}
