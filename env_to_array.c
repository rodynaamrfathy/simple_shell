#include "shell.h"

/**
 * env_to_array -  puts the file of env into an array
 * @env_array: array.
 *
 * Return: line_count  on success, -1 on failling
 */
int env_to_array(char *env_array[])
{
	char line[MAX_LINE_LENGTH];
	int line_count = 0;
	ssize_t bytes_read, i;
	int fd;

	fd = open("my_env_file", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening environment file");
		return (-1);
	}

	while((bytes_read = read(fd, line, sizeof(line))) > 0)
	{
		/* null terminate the line */
		line[bytes_read] = '\0';	

		env_array[line_count] = strdup(line);
		if (env_array[line_count] == NULL)
		{
			perror("Memory allocation error");
			return -1;
		}

		line_count++;

		if (line_count >= MAX_LINES)
		{
			perror("error.\n");
			return (-1);
		}

		if (bytes_read == -1)
		{
			perror("error reading the file");
			return (-1);
		}
	}
	close(fd);

	/* Add the PATH environment variable to the array */
	env_array[line_count] = getenv("PATH");

	return (line_count);
}
