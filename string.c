#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: The string to get the length of
 *
 * Return: The length of @s
 */

int _strlen(const char *s)
{
	int length = 0;

	while (*s++)
		length++;
	return (length);
}

/**
 * _strcpy - Copies a string
 * @dest: Where to copy the string to
 * @src: The source string
 *
 * Return: @dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 *
 * Return: A pointer to @dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = _strlen(dest);

	for (j = 0; src[j] != '\0'; i++, j++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Duplicates a string
 * @str: The string to duplicate
 *
 * Return: A pointer to the duplicated string
 */

char *_strdup(const char *str)
{
	char *dup;
	unsigned int i, len;

	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[len] = '\0';
	return (dup);
}
