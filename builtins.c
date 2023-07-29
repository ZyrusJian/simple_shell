#include "shell.h"

/**
 * builtin_cd - Change current working directory
 * @args: Argument array
 *
 * Return: Always 0 on success, 1 on failure
 */

int builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Expected argument to \"cd\"\n");
		return (1);
	}
	if (chdir(args[1]) != 0)
	{
		perror("chdir");
		return (1);
	}
	return (0);
}

/**
 * builtin_env - Print the environment
 * @args: Argument array, not used
 *
 * Return: Always 0 (success)
 */

int builtin_env(char **args)
{
	char **var = environ;

	(void) args;
	while (*var != NULL)
	{
		printf("%s\n", *var);
		var++;
	}
	return (0);
}

/**
 * builtin_exit - Exits the shell
 * @args: Argument array
 *
 * Return: Always 0 (success)
 */

int builtin_exit(char **args)
{
	(void) args;
	exit(EXIT_SUCCESS);
	return (0);
}

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
		return (builtin_func(args));

	return (1); /* Default to continue */
}
