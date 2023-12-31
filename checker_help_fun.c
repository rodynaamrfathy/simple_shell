#include "shell.h"

/**
 * full_path - check if argument is full_path
 * @argument: string to test
 * Return: result of access (0)success
 */
int full_path(char *argument)
{
	return (access(argument, X_OK));
}

/**
 * small_path - check if arfument is small_path
 * @argument: string to test
 * @path: array of separted paths to contactenate to argument
 * Return: allocated full path (success) NULL (fail)
 */
char *small_path(char *argument, char **path)
{
	char *fullpath;

	while (*path != NULL)
	{
		fullpath =  _strconcat(*path, argument);
		if (full_path(fullpath) == 0)
		{
			return (fullpath);
		}
		free(fullpath);
		path++;
	}
	return (NULL);
}
