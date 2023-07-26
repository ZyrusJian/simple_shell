
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
		printf("simple_shell$ ");
		info.input = read_line();
		info.args = split_line(info.input);
		info.status = execute(&info);
	}
	free(info.input);
	free(info.args);

	return (0);
}

