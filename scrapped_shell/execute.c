#include "shell.h"

/**
 * execute - executes commands
 * @info: shell info struct
 * Return: 1 on success, 0 on failure
 */

int execute(info_t *info)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork error");
		return (1);
	}

	/* child process */
	if (child_pid == 0)
	{
		if (execve(info->args[0], info->args, info->av) == -1)
		{
			perror("execve error");
			return (1);
		}
	}
	else /* parent process */
	{
		do {
			waitpid(child_pid, &status, wuntraced);
		} while (!wifexited(status) && !wifsignaled(status));
	}

	return (0);
}
