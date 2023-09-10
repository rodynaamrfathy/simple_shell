#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main -   a program that prints "$ ", wait for the user to enter a command, prints it on the next line.
 * @ac: counter
 * @av: vector
 *
 * return: 0 on success and -1 on failing
 */
int main()
{
	char *line = NULL, *line_cpy = NULL, *delim = "\" \'`\\*&#", *token = NULL;
	size_t len = 0;
	ssize_t read;
	int argc, i = 0;
	char **argv;

	/**
	 * start Display a prompt and wait for the user to type a command
	 * then put it in argv
	 * then print it bs to know if it works
	 */
	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			perror("getline");
			break;
		}

		line_cpy = strdup(line);
		token = strtok(line, delim);
		argc = 1;
		/**
		 * increment argc to malloc argv
		 */
		while (token)
		{
			token = strtok(NULL, delim);
			argc++;
		}

		argv = malloc(sizeof(char *) * argc);
		if(argv == NULL)
		{
			perror("malloc");
			break;
		}

		i  = 0;
		token = strtok(line_cpy, delim);
		while(token)
		{
			argv[i] = token;
			token = strtok(NULL, delim);
			i++;
		}

		argv[argc - 1] = NULL;

		/**
		 * print argv
		 */
		i = 0;
		while (argv[i])
		{
			printf("%s\n", argv[i]);
			i++;
		}
		printf("%d", argc);
		free(argv);
		free(line_cpy);
	}
	free(line);
	return (0);
}
