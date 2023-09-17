#include "shell.h"
/**
 * cdd - done the cd
 * @argv: element to check
 */
void cdd(char *argv[])
{
	char previous_directory[MAX_LINE_LENGTH];
	previous_directory[0] = '\0';

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
				printf("%s\n", previous_directory);
				chdir(previous_directory);
			}
			else
			{
				printf("No previous directory available.\n");
			}
		}
		else
		{
			getcwd(previous_directory, sizeof(previous_directory));
			chdir(argv[1]);
		}
	}
}
/**
 * child_check - check the child pid
 * @argv: element to check
 */
void child_check(char *argv[])
{
	char command_path[256];
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
	}
	else if (child_pid == 0)
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
/**
 * read_check - check the read
 * @line: line to check
 */
void read_check(char *line)
{
	printf("\nDisconecting...\n");
	free(line);
	exit(0);
}
/**
 * main - simple shell
 * Description: gg
 * Return: 0 on success and -1 on failing
 */
int main(void)
{
	char *line = NULL, *delim = " \n", *token = NULL, *argv[10];
	int len = 0, i = 0;
	ssize_t read;

	while (1)
	{
		printf("HOME$ ");
		read = _getline(&line, &len);
		if (read == -1)
		{
			read_check(line);
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
		if (strcmp(argv[0], "cd") == 0)
		{
			cdd(argv);
			continue;
		}
		else if (strcmp(argv[0], "env") == 0)
		{
			print_environment(environ);
			continue;
		}
		else if (strcmp(argv[0], "exit") == 0)
		{
			printf("[Disconnected...]\n");
			free(line);
			exit(0);
		}
	}
	free(line);
	return (0);
}
