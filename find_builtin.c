#include "shell.h"

/**
 * find_builtin - Finds a built-in command.
 * @args: The command and its arguments as an array of strings.
 *
 * Return: The index of the built-in command found, -1 if not found.
 */

int find_builtin(char **args)
{
	const char *builtins[] = {"exit", "env", "cd"};
	int num_builtins = sizeof(builtins) / sizeof(char *);
	int i;

	for (i = 0; i < num_builtins; i++)
	{
		if (strcmp(builtins[i], args[0]) == 0)
			return (i);
	}

	return (-1);
}
