#include "shell.h"

/**
 * cdd - changing directory
 * @argv: argv
 * @previous_directory: prev
 * @prev_directory_size: size of previous_directory array
 *
 * Return: nothing
 */
void cdd(char *argv[], char previous_directory[], size_t prev_directory_size)
{
	if (argv[1] == NULL)
		chdir(getenv("HOME"));
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
			if (getcwd(previous_directory, prev_directory_size) != NULL)
			{
				chdir(argv[1]);
			}
			else
			{
				perror("getcwd");
			}
		}
	}
}
