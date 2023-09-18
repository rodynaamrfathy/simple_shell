#include "shell.h"

/**
 * main - simple shell
 *
 * Return: 0 on success and -1 on failing
 */
int main(void)
{
	char *line = NULL, *delim = " \n", *token = NULL;
	size_t len = 0;
	int i = 0;
	char *argv[10], previous_directory[MAX_LINE_LENGTH];

	while (1)
	{
		printf("HOME$ ");
		if (getline(&line, &len, stdin) == -1)
		{
			_sprintf("\nDisconnecting...\n");
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
			cdd(argv, previous_directory, sizeof(previous_directory));
		}
		else if (_strcmp(argv[0], "env") == 0)
		{
			print_environment(environ);
		}
		else if (_strcmp(argv[0], "exit") == 0)
		{
			_sprintf("[Disconnecting...]\n");
			free(line);
			exit(0);
		}
		else
		{
			int status;
        		char command_path[256];
        		pid_t child_pid;

        		child_pid = fork();
        		if (child_pid == -1)
        		{	
                		perror("fork");
                		exit(1);
        		}
        		if (child_pid == 0)
        		{
                		snprintf(command_path, sizeof(command_path), "/usr/bin/%s", argv[0]);
                		execve(command_path, argv, environ);
                		perror("execve failed");
                		exit(1);
        		}
        		else
        		{
                		waitpid(child_pid, &status, 0);
       			}
		}
	}
	free(line);
	return (0);
}
