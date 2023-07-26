#include "shell.h"

/**
 * main - entry point for the shell program
 * @ac: number of arguments passed to the program
 * @av: array of strings containing the arguments
 * @env: array of strings containing the environment variables
 *
 * Return: 0 on successful execution
 */
int main(int __attribute__((unused)) ac, char **av, char **env)
{
	info_t info;

	info.av = av;
	info.env = env;

	/* shell main loop */
	while (1)
	{
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
		info.input = read_line();
		info.args = split_line(info.input);

		if ((info.args[0]) != NULL)
		{
			info.status = execute(&info);
		}
		else
		{
			printf("Error: Executable not found %s\n", info.args[0]);
			free(info.input);
			free(info.args);
		}
		free(info.input);
		free(info.args);
	}
	return (0);
}

