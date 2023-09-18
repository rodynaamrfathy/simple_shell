#include "shell.h"

/*Declaration of the environ array*/
extern char **environ;

/**
 * main - simple shell
 *
 * return: 0 on success and -1 on failing
 */
int main(void)
{
	char *line = NULL, *delim = " \n", *token = NULL;
	size_t len = 0;
	ssize_t read;
	int i = 0;
	char *argv[10];
	pid_t child_pid;
	int status;
	char previous_directory[MAX_LINE_LENGTH], command_path[256];;

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

		i  = 0;
		token = strtok(line, delim);
		while (token)
		{
			argv[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		argv[i] = NULL;
		
		/* handel built-in commands*/
		if (_strcmp(argv[0], "cd") == 0) 
		{
			if (argv[1] == NULL)
			{
				chdir(getenv("HOME"));
			}
			else
			{
				if (strcmp(argv[1], "-") == 0)
				{
					if (previous_directory[0] != '\0')
					{
						_sprintf(previous_directory);
						_putchar('\n');
						chdir(previous_directory);
					}
					else
					{
						_sprintf("No previous directory available.\n");
					}
				}
				else
				{
					getcwd(previous_directory, sizeof(previous_directory));
					chdir(argv[1]);
				}
			}
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
			exit (0);
		}
		child_pid = fork();

		if (child_pid == -1)
		{
			/* Handle fork error*/
			perror("fork");
			break;
		}
		else if (child_pid == 0)
		{
			/* This code is executed in the child process
			* Get the PATH environment variable */
			snprintf(command_path, sizeof(command_path), "/usr/bin/%s", argv[0]);
			execve(command_path, argv, environ);
			perror("execve failed");
			exit(1);
		}
		else /* Parent process */
		{
			/* Wait for the child to finish */
			waitpid(child_pid, &status, 0);
		}
	}
	free(line);
	return (0);
}
