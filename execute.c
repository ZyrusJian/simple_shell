#include "shell.h"

/**
 * execute - execute a command
 * @info: shell info struct
 * Return: status code
 */

int execute(info_t *info)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork Error");
	}
	else if (pid == 0)
	{
		/* child process */
		if (execve(info->args[0], info->args, info->env) == -1)
		{
			perror("Execve Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (status);
}

