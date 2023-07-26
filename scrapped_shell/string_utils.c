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

	chars_read = getline(&line, &len, stdin);

	if (chars_read == -1)
	{
		free(line);
		exit(0);
	}

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

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIMS);
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;

		if (pos >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, DELIMS);
	}

	tokens[pos] = NULL;
	return (tokens);
}
