#include "shell.h"

/**
 * execute - Execute a command
 * @args: Null terminated argument array
 *
 * Return: 1 if the shell should continue, 0 if it should terminate
 */

int execute(char **args)
{
	int (*builtin_func)(char **);

	/* Check if command is a builtin */
	builtin_func = find_builtin(args[0]);
	if (builtin_func != NULL)
	{
		return (run_builtin(args));
	}
	else
	{
		/* If not a builtin, try to run command from PATH */
		return (run_path_cmd(args));
	}
	if (strcmp(args[0], "exit") == 0)
		exit(0);
	return (1);
}
