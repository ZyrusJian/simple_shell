#include "shell.h"

/**
 * split_line - Splits a line into tokens
 * @line: The line
 *
 * Return: An array of tokens
 */

char **split_line(char *line)
{
	int i;
	char **tokens = malloc(ARG_NUM * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("Allocation error");
		free(tokens);
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
