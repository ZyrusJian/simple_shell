#include "shell.h"

/**
 * init_shell - initializes the shell
 * @info: shell info struct
 *
 * This function initializes the shell by setting up the prompt,
 * reading the user input, splitting it into arguments, and executing
 * the command or built-in function. It also waits for the child process
 * to finish before executing the next command.
 */

void init_shell(info_t *info)
{
	pid_t child;
	int status;
	char *input;
	char **args;

	while (1)
	{
		print_prompt();
		input = read_input(info);
		args = split_input(input);

		if (find_builtin(info))
			continue;

		child = fork();
		if (child == 0)
			execute(info);

		wait(&status);
	}
}
