#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/**
 * struct info - shell info
 * @av: argument vector
 * @input: command line input
 * @args: tokenized arguments
 * @status: last command status
 * @env: environment list
 */
typedef struct info
{
	char **av;
	char *input;
	char **args;
	int status;
	char **env;
} info_t;

/* Function prototypes */
char *read_line(void);
char **split_line(char *line);
int run_cmd(info_t *info);
int find_builtin(char **args);
int run_builtin(info_t *info, int builtin_num);
int execute(info_t *info);

/* Built-in commands */
int shellby_exit(info_t *info);
int shellby_env(info_t *info);
int shellby_cd(info_t *info);

#endif /* SHELL_H */

