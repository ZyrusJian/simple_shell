#include "shell.h"

char *search_command(char *command);
char *create_temp_path(char *command, char *directory);
void wait_for_child(pid_t pid, int *status);

/**
 * run_cmd - Executes a command specified by the user.
 * @info: A pointer to the info_t structure containing command information.
 *
 * Return: 1 on success, 0 if command not found.
 */

int run_cmd(info_t *info)
{
	pid_t pid;
	int status;
	char *command_path = NULL;

	if (info->args[0][0] == '/')
		command_path = info->args[0];
	else
		command_path = search_command(info->args[0]);

	if (command_path == NULL)
	{
		fprintf(stderr, "command not found: %s\n", info->args[0]);
		return (0);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(command_path, info->args, info->env) == -1)
			fprintf(stderr, "error executing command: %s\n",
					info->args[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		fprintf(stderr, "fork error\n");
		exit(EXIT_FAILURE);
	}
	else
		wait_for_child(pid, &status);

	if (command_path != NULL && command_path != info->args[0])
		free(command_path);

	return (1);
}

/**
 * search_command - Searches for the command in the PATH env variable.
 * @command: The command to search for.
 *
 * Return: The absolute path of the command on success, NULL if not found.
 */

char *search_command(char *command)
{
	char *path = getenv("PATH");
	char *path_token = NULL;
	char *command_path = NULL;
	int command_found = 0;

	if (path != NULL)
	{
		path_token = strtok(path, ":");
		while (path_token != NULL)
		{
			command_path = create_temp_path(command, path_token);
			if (access(command_path, X_OK) == 0)
			{
				command_found = 1;
				break;
			}
			free(command_path);
			path_token = strtok(NULL, ":");
		}
	}

	return (command_found ? command_path : NULL);
}

/**
 * create_temp_path - Creates new temp path by appending cmd to a directory.
 * @command: The command to append.
 * @directory: The directory to append to.
 *
 * Return: The newly created path.
 */

char *create_temp_path(char *command, char *directory)
{
	char *temp_path = malloc(strlen(directory) + strlen(command) + 2);

	if (temp_path == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	sprintf(temp_path, "%s/%s", directory, command);
	return (temp_path);
}

/**
 * wait_for_child - Waits for the child process to finish.
 * @pid: The PID of the child process.
 * @status: A pointer to the status variable to store the child's exit status.
 */
void wait_for_child(pid_t pid, int *status)
{
	do {
		waitpid(pid, status, WUNTRACED);
	} while (!WIFEXITED(*status) && !WIFSIGNALED(*status));
}

