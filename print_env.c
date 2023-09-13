#include "shell.h"

/**
 * print_environment - a functions that prints the system env.
 *
 * Return: nothing.
 */
void print_environment(char **environ) 
{
	int i;

	for (i = 0; environ[i] != NULL; i++) 
	{
		printf("%s\n", environ[i]);
	}
}
