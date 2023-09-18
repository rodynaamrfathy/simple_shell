#include "shell.h"

/**
 * _getline - scan line
 * @line: buff to store line.
 * @len: len.
 *
 * Return: 0 on success, -1 on fail.
 */
int _getline(char **line, int *len)
{
	char buffer[1024], c;
	int buffer_size = 0, buffer_index = 0;

	if (line == NULL)
		return (-1);

	while (1)
	{
		if (buffer_index >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, 1024);
			buffer_index = 0;
			if (buffer_size < 0)
			{
				perror("read");
				return (-1); /* Handle read error */
			}
			else if (buffer_size == 0)
			{
				break; /* End of input */
			}
		}
		c = buffer[buffer_index++];
		if (c == '\n')
		{
			(*line)[*len] = '\0';
			break;
		}
		else
		{
			*line = _realloc(*line, (*len) * sizeof(char), (*len + 1) * sizeof(char));
			if (*line == NULL)
			{
				perror("_realloc");
				return (-1); /* Handle memory allocation error */
			}
			(*line)[(*len)++] = c;
		}
	}
	return (*len);
}
