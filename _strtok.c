#include "shell.h"

/**
 * _strtok - function involves parsing a string and splitting it into tokens
 * based on a delimiter character.
 * @str: string.
 * @delimiters: to be deleted.
 *
 * Return: token
 */
char *_strtok(char *str, const char *delimiters)
{
	static char *nextToken = NULL;
	char *tokenStart;

	if (str != NULL)
		nextToken = str;
}
