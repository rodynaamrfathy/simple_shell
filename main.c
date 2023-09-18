#include "shell.h"

/**
 * main - simple shell
 *
 * Return: 0 on success and -1 on failing
 */
int main(void)
{
	while (1)
	{
		printf("HOME$ ");
		if (_getline(&line, &len) == -1)
		{
			printf("\nDisconnecting...\n");
			free(line);
			exit(0);
		}
		token = _strtok(line, delim);
		while (token)
		{
			argv[i] = token;
			token = _strtok(NULL, delim);
			i++;
		}
		argv[i] = NULL;
		if (_strcmp(argv[0], "cd") == 0)
		{
			cdd(argv, previous_directory, sizeof(previous_directory));
		}
		else if (_strcmp(argv[0], "env") == 0)
		{
			print_environment(environ);
		}
		else if (_strcmp(argv[0], "exit") == 0)
		{
			printf("[Disconnecting...]\n");
			free(line);
			exit(0);
		}
		else
		{
			_shell();
		}
	}
	free(line);
	return (0);
}
