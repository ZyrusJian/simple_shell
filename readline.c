#include "shell.h"

/**
 * read_line - Reads a line from stdin
 *
 * Return: A pointer to the read line
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	/* Read line using getline */
	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			/* End of file condition (ctrl+d) */
			free(line);
			line = NULL;
			exit(0);
		}
		else
		{
			perror("getline");
			exit(1);
		}
	}
	return (line);
}

