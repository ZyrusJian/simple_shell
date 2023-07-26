#include "shell.h"

/**
 * execute - execute a command
 * @info: shell info struct
 * Return: status code
 */

int execute(info_t *info)
{
	int is_builtin;
	is_builtin = find_builtin(info->args);
	if (is_builtin != -1)
	{
		return run_builtin(info, is_builtin);
	}
	else
	{
		return run_cmd(info);
	}
}

