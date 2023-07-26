#include "shell.h"

/**
 * run_cmd - execute a command based on the given info
 * @info: pointer to the shell info struct
 *
 * Return: status of the execution
 */
int run_cmd(info_t *info)
{
	pid_t child_pid;
	int status;
	int command_found = 0;
	int builtin_num = find_builtin(info->args);

	if (builtin_num >= 0)
	{
		return (run_builtin(info, builtin_num));
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* child process */
		command_found = execute(info);
		if (command_found == -1)
		{
			printf("%s: command not found\n", info->args[0]);
			exit(127);
		}
		execve(info->args[0], info->args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* parent process */
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
		{
			info->status = WEXITSTATUS(status);
		}
	}
	return (info->status);
}
