#include "shell.h"

/**
 * read_line - read a line of input from the terminal
 *
 * Return: The read line as a string
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	/* Read line using getline */
	getline(&line, &bufsize, stdin);

	/* Check for EOF */
	if (feof(stdin))
	{
		free(line);
		line = NULL;
	}

	return (line);
}

