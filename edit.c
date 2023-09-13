#include "shell.h"

extern char **environ; // Declaration of the environ array

// Function to print the current environment
void print_environment() {
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}

/**
 * main - simple shell
 *
 * return: 0 on success and -1 on failing
 */
int main(void)
{
	char *line = NULL, *line_cpy = NULL, *delim = "\" \'`\\*&#", *token = NULL;
	size_t len = 0;
	ssize_t read;
	int argc, i = 0;
	char *argv[10];
	pid_t child_pid;
	char *full_path, *path;
	int status;
	char previous_directory[MAX_LINE_LENGTH];

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

		line_cpy = strdup(line);
		token = strtok(line, delim);
		argc = 0;

		/* increment argc to malloc argv */
		while (token)
		{
			argc++;
			token = strtok(NULL, delim);
		}

		argv = malloc(sizeof(char *) * (argc + 1));
		if (argv == NULL)
		{
			perror("malloc");
			break;
		}

		i  = 0;
		token = strtok(line_cpy, delim);
		while (token)
		{
			argv[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		argv[argc] = NULL;
		
		/* handel built-in commands*/
		if (strcmp(argv[0], "cd") == 0) 
		{
			chdir(argv[1]);
			continue;
		}
		else if (strcmp(argv[0], "exit") == 0)
		{
			printf("[Disconnected...]\n");
			free(line);
			exit (0);
		}
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			/* Handle fork error */
			free(line_cpy);
			perror("fork");
			break;
		}
		else if (child_pid == 0)
		{
			/* This code is executed in the child process
			* Get the PATH environment variable */
			path = getenv("PATH");

			/* Search for the command in the PATH */
			full_path = malloc(strlen(path) + strlen(argv[0]) + 2);
			strcpy(full_path, path);
			strcat(full_path, "/");
			strcat(full_path, argv[0]);

			if (execve(full_path, argv, env_strings) == -1)
			{
				perror("exec");
				exit(EXIT_FAILURE);
			}
		}
		else /* Parent process */
		{
			/* Wait for the child to finish */
			waitpid(child_pid, &status, 0);
		}

		free(argv);
		free(line_cpy);
	}
	free(line);
	return (0);
}