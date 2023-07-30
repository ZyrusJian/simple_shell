#include "shell.h"

/**
 * run_builtin - Runs a builtin command
 * @args: Null terminated argument array
 *
 * Return: 1 if the shell should continue, 0 if it should terminate
 */

int run_builtin(char **args)
{
	int (*builtin_func)(char **);

	builtin_func = find_builtin(args[0]);
	if (builtin_func != NULL)
	{
		return (builtin_func(args));
	}

	return (1); /* Default to continue */
}
