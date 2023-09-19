#include "shell.h"

/**
 * main - Entry point.
 *
 * Return: 0 on success, -1 on fail.
 */
int main(void)
{
	size_t len = 0;
	ssize_t read;
	char *line = NULL, **argv = NULL, previous_directory[MAX_LINE_LENGTH];

	while (1)
	{
	_sprintf("HOME$ ");
	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		_sprintf("\nDisconecting...\n");
		free(line);
		free(argv);
		exit(0);
	}
	_argv(&argv, line);
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
		free(argv);
		exit(0);
	}
	else
		_shell(argv);
	}
	free(line);
	free(argv);
	return (0);
}
