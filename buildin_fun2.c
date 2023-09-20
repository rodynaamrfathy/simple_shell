#include "shell.h"

/**
 * set_environ - set environ at idx i
 * @i: index
 * @arg1: variable name
 * @arg2: value
 */
void set_environ(int i, char *arg1, char *arg2)
{
int length1 = _strlen(arg1);
int length2 = _strlen(arg2);
int totallen = length1 + length2 + 2;
int j = 0;
int index = 0;

environ[i] = malloc(totallen);
if (!environ[i])
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}

for (j = 0; j < length1; j++)
{
environ[i][index] = arg1[j];
index++;
}
environ[i][index] = '=';
index++;
for (j = 0; j < length2; j++)
{
environ[i][index] = arg2[j];
index++;
}
environ[i][index] = '\0';
}

/**
 * copy_array2 - hard copy
 * @str: array of strings
 * Return: allocated new copy array
 */
char **copy_array2(char **str)
{
int con = 0;
char **array = str;
int i;

while (*array)
{
con++;
array++;
}
array = malloc(sizeof(char *) * (con + 2));
if (!array)
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}

for (i = 0; i < con; i++)
{
array[i] = _strcopy(str[i]);
if (!array[i])
{
perror("Memory allocation failed");
free_array(array);
exit(EXIT_FAILURE);
}
}
array[con + 1] = NULL;

return (array);
}

/**
 * setenv_var - set the environment
 * @arguments: splitted string according to breaks
 * Return: EXIT_SUCCESS = 0
 */
int setenv_var(char **arguments)
{
int i = 0, j;
int len = 0;
char **newenviron = NULL;
if (arguments[1] != NULL && arguments[2] != NULL)
{
len = _strlen(arguments[1]);
while (environ[i])
{
for (j = 0; j <= len; j++)
{
if (arguments[1][j] != environ[i][j])
break;
}
if (j == len)
{
free(environ[i]);
set_environ(i, arguments[1], arguments[2]);
return (EXIT_SUCCESS);
}
i++;
}

newenviron = copy_array(environ);
if (!newenviron)
{
perror("Memory allocation failed");
return (EXIT_FAILURE);
}

free_array(environ);
environ = newenviron;

set_environ(i, arguments[1], arguments[2]);
}
else
{
return (EXIT_FAILURE);
}
return (EXIT_SUCCESS);
}

/**
 * unsetenv_var - unset the environment
 * @arguments: splitted string according to breaks
 * Return: EXIT_SUCCESS = 0
 */
int unsetenv_var(char **arguments)
{
int i = 0, j;
int length = 0;
if (arguments[1] != NULL)
{
length = _strlen(arguments[1]);
while (environ[i])
{
for (j = 0; j <= length; j++)
{
if (arguments[1][j] != environ[i][j])
break;
}
if (j == length)
{
/* remove variable*/
rem_index(i, environ);
return (EXIT_SUCCESS);
}
i++;
}
}
return (EXIT_FAILURE);
}
