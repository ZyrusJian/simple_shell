#include "shell.h"

/**
 * execute - executes input commands
 * @info: shell info struct
 * Return: 1 on success, 0 on failure
 */

int execute(info_t *info)
{
	if (execve(info->args[0], info->args, info->av) == -1)
	{
		/* handle execve errors */
		return (1);
	}

	return (0);
}
