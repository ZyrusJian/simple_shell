#include "shell.h"

/**
 * main - Simple shell entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	pid_t pid;
	char *line, **args;
	int status = 0;

	while (1)
	{	/* Print prompt and read input */
		printf("simple_shell$ ");
		line = NULL;
		args = NULL;
		line = read_line();
		args = split_line(line); /* Split input into tokens */
		if ((args[0] == NULL) || (strcmp(args[0], DELIM) == 0))
			return (1);
		pid = fork(); /* Fork a child process */
		if (pid == 0)
		{	/* Execute command */
			status = execute(args);
			exit(EXIT_SUCCESS);
		}
		else if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		} /* Exit if command was "exit" */
		if ((status == 0) && (strcmp(args[0], "exit") == 0))
		{
			free(line);
			free(args);
			exit(0);
		} /* Free memory */
		free(line);
		free(args);
	}
	return (0);
}
