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
	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			/* End of file condition (ctrl+d) */
			printf("End of file reached. Exiting...\n");
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

