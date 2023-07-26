#include "shell.h"

/**
 * shellby_exit - Exit the shell
 * @info: Shell information
 * Return: Always 0
 */
int shellby_exit(info_t *info)
{
	exit(info->status);
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
	char *homedir;
	char *oldpwd;
	char buf[1024];

	/* null argument - change to home */
	if (info->args[1] == NULL)
	{
		homedir = getenv("HOME");
		if (chdir(homedir) != 0)
		{
			perror("No Such directory");
			return (-1);
		}
	}
	else if (strcmp(info->args[1], "-") == 0)
	{
		homedir = getenv("OLDPWD");
		if (homedir == NULL)
		{
			fprintf(stderr, "OLDPWD not set\n");
			return (-1);
		}
		if (chdir(homedir) != 0)
		{
			perror("No Such directory");
			return (-1);
		}
	}
	else
	{
		/* cd to specified directory */
		if (chdir(info->args[1]) != 0)
		{
			perror("No Such directory");
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
		perror("No Such directory");
		return (-1);
	}

	return (0);
}
