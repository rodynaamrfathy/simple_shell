#include "shell.h"

/**
 * main - Entry point.
 *
 * Return: 0 on success, -1 on fail.
 */
int main(void)
{
	char *line = NULL, *delim = " \n", *token = NULL;
	size_t len = 0;
	ssize_t read;
	int i = 0;
	char *argv[10], previous_directory[MAX_LINE_LENGTH];

	while (1)
	{
	_sprintf("HOME$ ");
	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		_sprintf("\nDisconecting...\n");
		free(line);
		exit(0);
	}
	token = strtok(line, delim);
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	if (_strcmp(argv[0], "cd") == 0)
	{
		cdd(argv, previous_directory, 80);
		continue;
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		print_environment(environ);
		continue;
	}
	else if (_strcmp(argv[0], "exit") == 0)
	{
		_sprintf("[Disconnected...]\n");
		free(line);
		exit(0);
	}
	else
		_shell(argv);
	}
	free(line);
	return (0);
}
