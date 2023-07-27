#include "shell.h"

/**
 * split_line - tokenize an input line into arguments
 * @line: input line as a string
 *
 * Return: array of strings containing the arguments
 */

char **split_line(char *line)
{
	char **args = NULL;
	char *token;
	int i = 0;
	int bufsize = 64;

	args = malloc(bufsize * sizeof(char *));
	if (!args)
	{
		perror("Memory allocation error");
		free(args);
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		args[i] = token;
		i++;

		if (i >= bufsize)
		{
			args = realloc(args, (bufsize) * sizeof(char *));
			if (!args)
			{
				perror("Memory allocation error");
				free(args);
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	args[i] = NULL;

	return (args);
}

