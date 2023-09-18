#include "shell.h"

/**
 * _strcmp - used to compare two strings.
 * @str1: first string.
 * @str2: 2nd string.
 *
 * Return:  An integer less than, equal to, or greater than zero
 * if str1 is found, respectively, to be less than, to match, or be
 * greater than str2.
 */
int _strcmp(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (-1);

	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			return (*str1 - *str2);

		str1++;
		str2++;
	}

	/*
	 * using ascii code to return value will retrun 0 only
	 * if it passes the while
	 * loop so strings match and
	 * if the length of the str1 & str2 are equal
	 */
	return (*str1 - *str2);
}
