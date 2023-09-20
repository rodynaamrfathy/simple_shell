#include "shell.h"

/**
 * get_environ - get environment from environ
 * @string: environment to search in environ
 * Return: address of its value if  found - NULL if not
 */
char *get_environ(char *string)
{
	int len = _strlen(string);
	int i = 0;

	while (environ[i] != NULL)
	{
		if (_strcmp(string, environ[i]) == 0)
		{
			return (&environ[i][len + 1]);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_path - split the found path into paths
 * Return: splitted paths (allocated in memory)
 */
char **get_path(void)
{
	char *_path = get_environ("PATH");
	char *path_copy = _strcopy(_path);
	char **splitted_paths = _split(path_copy, ":");
	char **_copy_splitted_paths = copy_array(splitted_paths);

	free(path_copy);
	free(splitted_paths);
	return (_copy_splitted_paths);
}
