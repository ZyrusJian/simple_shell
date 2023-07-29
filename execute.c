#include "shell.h"

/**
 * execute - Execute a command
 * @args: Null terminated argument array
 *
 * Return: 1 if the shell should continue, 0 if it should terminate
 */

int execute(char **args)
{
	pid_t pid;
	int status;

	/**
	 * Fork a child process
	 */
	pid = fork();

	if (pid == 0)
	{
		/* Child process */

		/* Check if command is a builtin */

		if (run_builtin(args))
			exit(EXIT_SUCCESS);

		/* If not a builtin, try to run command from PATH */
		if (run_path_cmd(args))
			exit(EXIT_SUCCESS);

		/* If not found, return error */
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (status);
}
