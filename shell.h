#ifndef SHELL_H
#define SHELL_H

/* Headrs */
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>


/**
 * struct list_s - A linked list
 * @str: A string
 * @len: The length of the string
 * @next: A pointer to the next node
 * Description: Simple linked list implementation used for path storage
 */

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;


#define ARG_MAX 1024 /* Max arg length */
#define ARG_NUM 128 /* Max arg count */
#define DELIM " \t\r\n\a"

/* Global environ, a pointer to an array of char * strings */
extern char **environ;

/* Function prototypes */
char *read_line(void);
char **split_line(char *line);
int execute(char **args);

int builtin_cd(char **args);
int builtin_exit(char **args);
int builtin_env(char **args);
int (*find_builtin(char *command))(char **);
int run_builtin(char **args);

int run_path_cmd(char **args);
list_t *add_node(list_t **head, char *str);
list_t *construct_path(void);

int _putchar(char c);
char *_strcat(char *dest, char *src);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);

#endif /* SHELL_H */
