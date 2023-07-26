#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

/**
 * struct counters - Command and line counters
 * @lines: number of lines
 * @commands: number of commands
 */

typedef struct counters
{
	unsigned int lines;
	unsigned int commands;
} counters_t;

/**
 * struct info - shell info
 * @av: argument vector
 * @input: command line input
 * @args: tokenized arguments
 * @status: most recent command status
 * @counters: command and line counters
 */

typedef struct info
{
	char **av;
	char *input;
	char **args;
	int status;
	counters_t counters;
} info_t;

/**
 * struct builtin - matches command to builtin function
 * @command: command name
 * @func: function pointer for command
 */

typedef struct builtin
{
	char *command;
	int (*func)(info_t *);
} builtin_t;

void init_shell(info_t *info);
char *read_input(info_t *info);
char **split_input(char *input);
int execute(info_t *info);
int find_builtin(info_t *info);
int exit_shell(info_t *info);

#endif /* SHELL_H */

