#include "shell.h"

/**
 * run_builtin - run a builtin command
 * @info: shell info struct
 * @builtin_num: index of builtin to run
 *
 * Return: result of running builtin
 */

int run_builtin(info_t *info, int builtin_num)
{
	int (*builtin_funcs[])(info_t *) = {
		&shellby_exit,
		&shellby_env,
		&shellby_cd
	};

	return (builtin_funcs[builtin_num](info));
}

