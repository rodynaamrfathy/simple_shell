#include "shell.h"

/**
 * _str_concat - add str2 command to str1 path
 * @str1: first string
 * @str2: second string
 * Return: str1 after addition
 */
char *_str_concat(char *str1, char *str2)
{
int str1_len, str2_len, i;
char *full_str = NULL;

i = 0;
str1_len = _strlen(str1);
str2_len = _strlen(str2);
/* 2 for / , \0 chars */
full_str = malloc(str1_len + str2_len + 3);
for (i = 0; i < str1_len; i++)
full_str[i] = str1[i];

full_str[i++] = ':';
full_str[i] = ' ';

for (i = 0; i < str2_len; i++)
full_str[(i + str1_len)+2] = str2[i];

full_str[str1_len + str2_len + 2] = '\0';
return (full_str);
}
