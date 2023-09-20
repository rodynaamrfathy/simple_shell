#include "shell.h"

/**
 * _strlen - string length
 * @str: array of charahcters null terminated
 * Return: length of string
 */
int _strlen(char *str)
{
int i = 0;

while (str && str[i] != '\0')
i++;

return (i);
}
/**
 * _strcmp - compared two strings
 * @str1: first one
 * @str2: seocnd one
 * Return: (0) match (1) not match
 */
int _strcmp(char *str1, char *str2)
{
int p = 0;

while (str1[p])
{
if (str1[p] != str2[p])
return (1);
p++;
}
return (0);
}

/**
 * _strcopy - copy str to new allocated one and return it
 * @str: source
 * Return: newly allocated string copy of source
 */
char *_strcopy(char *str)
{
int len, i = 0;
char *strcopy = NULL;

len = _strlen(str);
/* 1 to null character */
strcopy = malloc(len + 1);
while (i < len && str[i])
{
strcopy[i] = str[i];
i++;
}
strcopy[i] = '\0';
return (strcopy);
}

/**
 * _strconcat - add str2 command to str1 path
 * @str1: first string
 * @str2: second string
 * Return: str1 after addition
 */
char *_strconcat(char *str1, char *str2)
{
int str1_len, str2_len, i;
char *full_str = NULL;

i = 0;
str1_len = _strlen(str1);
str2_len = _strlen(str2);
/* 2 for / , \0 chars */
full_str = malloc(str1_len + str2_len + 2);
for (i = 0; i < str1_len; i++)
full_str[i] = str1[i];

full_str[i] = '/';

for (i = 0; i < str2_len; i++)
full_str[(i + str1_len)+1] = str2[i];

full_str[str1_len + str2_len + 1] = '\0';
return (full_str);
}
/**
 * rm_comment - remove comment # from string
 * @str: string from stander input
 */
void rm_comment(char *str)
{
int i = 0;
while (str && str[i] != '\0')
{
if (str[i] == ' ' && str[i + 1] == '#')
{
str[i] = '\0';
break;
}
i++;
}
}
