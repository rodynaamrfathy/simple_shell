#include "shell.h"

/**
 * _snprintf - It is typically used to write formatted data to
 *		a string buffer instead of printing it to the standard output.
 * @str: buffer.
 * @size: size_t
 * @str1: arguments to be added to append to the buffer
 * @str2: arguments to be added to append to the buffer
 * Description: function used to instead snprintf function
 * Retunr: 0 on succeess, -1 on fail.
 */
int _snprintf(char *str, size_t size, char *str1, char *str2)
{
	size_t total_length;

	if (str1 == NULL || str2 == NULL)
		return (-1);

	total_length = custom_strlen(str1) + custom_strlen(str2);

	if (total_length >= size)
		return (-1);

	while (*str1 != '\0')
	{
		*str = *str1;
		str++;
		str1++;
	}

	while (*str2 != '\0')
	{
		*str = *str2;
		str++;
		str2++;
	}

	*str = '\0';
	return (0);
}
