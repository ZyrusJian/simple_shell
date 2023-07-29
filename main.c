#include "shell.h"

/**
 * main - Simple shell entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	char *line;
	char **args;
	int status;

	while (1)
	{
		/* Print prompt and read input */
		printf("simple_shell$ ");
		line = read_line();
		/* Split input into tokens */
		args = split_line(line);

		/* Execute command */
		status = execute(args);

		/* Free memory */
		free(line);
		free(args);

		/* Exit if command was "exit" */
		if (status == 0)
			break;
	}
	return (0);
}
