#include "shell.h"

/**
 * _sprintf - a function to print a string
 * @str: to pass argument passed to _printf
 *
 * Return: Nothing.
 */
void _sprintf(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}
