
#include <stdlib.h>
#include <stdio.h>
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

