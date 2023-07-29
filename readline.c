#include "shell.h"

/**
 * read_line - Reads a line from stdin
 *
 * Return: A pointer to the read line
 */

char *read_line(void)
{
	char *line = NULL;
	size_t size = 0;

	if (getline(&line, &size, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		perror("readline");
		exit(EXIT_FAILURE);
	}
	return (line);
}
