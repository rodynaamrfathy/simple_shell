#include "shell.h"

/**
 * main - simple shell
 *
 * return: 0 on success and -1 on failing
 */
int main(void)
{
	char *line = NULL, *delim = " \n", *token = NULL;
	size_t len;
	ssize_t read;
	int i = 0;
	char *argv[MAX_ARGV];
	pid_t child_pid;
	char full_path[MAX_LINE_LENGTH], *path;
	size_t path_len;
	int status;

	while (1)
	{
		printf("HOME$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			printf("\nDisconecting...\n");
			free(line);
			exit(0);
		}

		argv[i] = strtok(line, delim);
		while (token)
		{
			i++;
			argv[i] = strtok(NULL, delim);
		}
		argv[i] = NULL;
		
		/* handel built-in commands*/
		if (strcmp(argv[0], "cd") == 0) 
		{
			chdir(argv[1]);
			continue;
		}
		else if (strcmp(argv[0], "exit") == 0)
		{
			printf("[Disconnected...]\n");
			exit (0);
		}
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			/* Handle fork error */
			perror("fork");
			break;
		}
		else if (child_pid == 0)
		{
			/* This code is executed in the child process
			* Get the PATH environment variable */
			path = "/bin/";
			path_len = strlen(path);
			/* Search for the command in the PATH */
			strncpy(full_path, path, path_len);
			strncpy(full_path + path_len, argv[0], MAX_LINE_LENGTH - path_len);
			execve(full_path, argv, NULL);
			perror("execve failed");
			exit(1);
		}
		else /* Parent process */
		{
			/* Wait for the child to finish */
			waitpid(child_pid, &status, 0);
		}
	}
	return (0);
}
