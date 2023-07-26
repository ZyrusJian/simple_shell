#include "shell.h"

/**
 * run_cmd - execute a command based on the given info
 * @info: pointer to the shell info struct
 *
 * Return: status of the execution
 */

int run_cmd(info_t *info)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{

		if (execve(info->args[0], info->args, info->env) == -1)
		{
			fprintf(stderr, "Command not found\n");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		fprintf(stderr, "Fork error\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}

