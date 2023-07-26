#include "shell.h"

/**
 * main - entry point for simple shell
 * @ac: arg count
 * @av: arg vector
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	info_t info;

	info.av = av;
	info.status = 0;
	init_shell(&info);
	return (0);
}
