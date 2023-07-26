#include "shell.h"

/**
 * shellby_exit - Exit the shell
 * @info: Shell information
 * Return: Always 0
 */
int shellby_exit(info_t *info)
{
	free(info->input);
	free(info->args);
	exit(EXIT_SUCCESS);

	return (0);
}

/**
 * shellby_env - Print environment variables
 * @info: Shell information
 * Return: Always 0
 */
int shellby_env(info_t *info)
{
	int i;
	char *env_var;

	for (i = 0; info->env[i] != NULL; i++)
	{
		env_var = info->env[i];
		printf("%s\n", env_var);
	}

	return (0);
}

/**
 * shellby_cd - change current directory
 * @info: Shell information
 *
 * Return: 0 on success, -1 on failure
 */

int shellby_cd(info_t *info)
{
	char buf[1024];
	const char *oldpwd;

	if (info->args[1] == NULL)
	{
		/* cd to home directory */
		const char *home_dir = getenv("HOME");

		if (home_dir == NULL)
		{
			perror("no such directory");
			return (-1);
		}
		if (chdir(home_dir) != 0)
		{
			perror("no such directory");
			return (-1);
		}
	}
	else if (strcmp(info->args[1], "-") == 0)
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
	{
		/* cd to specified directory */
		if (chdir(info->args[1]) != 0)
		{
			perror("no such directory");
			return (-1);
		}
	}

	/* update pwd and oldpwd environment variables */
	oldpwd = getenv("PWD");
	if (getcwd(buf, sizeof(buf)) != NULL)
	{
		setenv("OLDPWD", oldpwd, 1);
		setenv("PWD", buf, 1);
	}
	else
	{
		perror("no such directory");
		return (-1);
	}
	return (0);
}
