#include "shell.h"

/**
 * find_builtin - Locates a builtin command
 * @command: The command name
 *
 * Return: A function pointer to the corresponding builtin
 */

int (*find_builtin(char *command))(char **)
{
	char *builtins[] = {
		"cd",
		"env",
		"exit"
	};

	int (*funcs[])(char **) = {
		&builtin_cd,
		&builtin_env,
		&builtin_exit
	};

	int i, num_builtins;

	num_builtins = sizeof(funcs) / sizeof(int (*)(char **));
	for (i = 0; i < num_builtins; i++)
	{
		if (strcmp(command, builtins[i]) == 0)
			return (funcs[i]);
	}
	return (NULL);
}
