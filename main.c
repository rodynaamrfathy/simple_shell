#include "shell.h"

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
	char **argv;
	pid_t child_pid;
	char *env_strings[MAX_LINES];
	int env_count = env_to_array(env_strings);

	if (env_count < 0)
		return (-1);

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
			/* This code is executed in the child process */
			execve(argv[0], argv, env_strings);
			perror("exec");
			exit(EXIT_FAILURE);
		}
		else /* Parent process */
		{
			/* Wait for the child to finish */
			wait(NULL);
		}


		if (strcmp(argv[0], "exit") == 0)
		{
			free(line);
			free(argv);
			return (0);
		}

		free(argv);
		free(line_cpy);
	}
	free(env_strings);
	free(line);
	return (0);
}
