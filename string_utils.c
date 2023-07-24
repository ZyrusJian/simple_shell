#include "shell.h"

/**
 * read_input - reads input from stdin
 * @info: shell info struct
 *
 * Return: pointer to input buffer
 */

char *read_input(info_t *info)
{
	size_t buf_size = 0;
	ssize_t characters;
	char *input = NULL;

	/* getline to read stdin */
	/* handle eof / error */
	info->counters.lines++;

	return (input);
}

/**
 * split_input - splits input into tokens
 * @input: input string
 *
 * Return: pointer to tokenized input
 */

char **split_input(char *input)
{
	int buf_size = 64, position = 0;
	char *tokens = malloc(buf_size * sizeof(char));
	char *token;

	/* strtok to extract tokens */
	/* realloc if necessary */

	return (tokens);
}
