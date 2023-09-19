#include "shell.h"

/**
 * custom_strlen - str len
 * @str: string.
 *
 * Return: len
 */
size_t custom_strlen(const char *str)
{
	size_t length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

