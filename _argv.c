#include "shell.c"

/**
 * _argv - filliing the array of strings
 * @argv: argv.
 * @line: line to fill
 * Return: nothing
 */
void _argv(char ***argv, char *line)
{
	char *delim = " \n", *token = NULL;
	int i = 0;
	*argv = malloc(sizeof(char *) * 10);

	token = strtok(line, delim);
	while (token)
	{
		(*argv)[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	(*argv)[i] = NULL;
}
