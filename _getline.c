#include "shell.h"

/**
 * _getline - get line from cmd line
 * @buf: buffer.
 * @len: string len.
 * @fd: pointer to a file
 *
 * Return: -1 on fail, 0 success
 */
ssize_t _getline(char *buf, size_t len, int fd)
{
	ssize_t result;

	if (buf == NULL || len <= 0)
		return (-1);

	/* leave space for null termantion */
	result = read(fd, buf, len - 1);
	if (result == -1)
	{
		perror("read");
		return (-1);
	}

	buf[result] = '\0';

	return result;
}
