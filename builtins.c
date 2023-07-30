#include "shell.h"

/**
 * builtin_cd - Change current working directory
 * @args: Argument array
 *
 * Return: Always 0 on success, 1 on failure
 */

int builtin_cd(char **args)
{
	char buf[1024];
	const char *oldpwd;

	if (args[1] == NULL)
	{	/* cd to home directory */
		const char *home_dir = getenv("HOME");

		((home_dir == NULL) || (chdir(home_dir) != 0))
			? (perror("no such directory"), -1) : 0;
	}
	else if (strcmp(args[1], "-") == 0)
	{
		if (getenv("OLDPWD") == NULL)
		{
			setenv("OLDPWD", getenv("PWD"), 1);
		}
		else
		{
			chdir(getenv("OLDPWD"));
			setenv("OLDPWD", getenv("PWD"), 1);
			setenv("PWD", getcwd(buf, sizeof(buf)), 1);
		}
		printf("%s\n", getenv("PWD"));
	}
	else
	{	/* cd to specified directory */
		((args[1] != NULL) && (chdir(args[1]) != 0))
			? (perror("no such directory"), -1) : 0;
	} /* update pwd and oldpwd environment variables */
	oldpwd = getenv("PWD");
	if (getcwd(buf, sizeof(buf)) != NULL)
	{
		setenv("OLDPWD", oldpwd, 1);
		setenv("PWD", buf, 1);
		printf("%s\n", getenv("PWD"));
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
	return (0);
}

