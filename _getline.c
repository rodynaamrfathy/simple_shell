#include "shell.h"

int _getline(char **line, int *len)
{
	char buffer[1024];
	int buffer_index = 0;
	int buffer_size = 0;
	char c;

	if (line == NULL)
		return (-1);

	while (1)
	{	
		/* If the buffer is empty, read more input */
		if (buffer_index >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, 1024);
			buffer_index = 0;
			if (buffer_size <= 0)
			{
				break;
			}
		}		
		/* Read a character from the buffer */
 		c = buffer[buffer_index++];
		if (c == '\n')
			/* End of line, terminate the string */
			(*line)[*len] = '\0';
		break;
		else
		{
			*line = _realloc(*line, (*len + 1) * sizeof(char));
			(*line)[(*len)++] = c;
		}
	}
	return (*len);
}
