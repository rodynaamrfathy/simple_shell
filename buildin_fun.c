#include "shell.h"
/**
 * _printenv - print the environments
 * @arguments: splitted string acc to breaks
 * Return: EXIT_SUCCESS = 0
 */
int _printenv(__attribute__((unused)) char **arguments)
{
int len;
char **tem = environ;

while (tem && *tem)
{
len = _strlen(*tem);
write(STDOUT_FILENO, *tem, len);
write(STDOUT_FILENO, "\n", 1);
tem++;
}
return (EXIT_SUCCESS);
}
/**
 * set_env - set the environments
 * @key: splitted string acc to breaks
 * @value: splitted string acc to breaks
 * Return: EXIT_SUCCESS = 0
 */
int set_env(char *key, char *value)
{
char **argus = NULL;
argus = malloc(3 * sizeof(char *));
argus[1] = _strcopy(key);
argus[2] = _strcopy(value);
setenv_var(argus);
free_array(argus);
return (EXIT_SUCCESS);
}
/**
 * _cdd - change directory
 * @arguments: splitted string acc to breaks
 * Return: EXIT_SUCCESS = 0
 */
int _cdd(char **arguments)
{
char *new_pwd = NULL;
char *_oldpwd = NULL;

if (arguments[1] == NULL)
{
arguments[1] = get_environ("HOME");
}
/* If the directory is '-', change to the previous directory*/
if (arguments[1][0] == '-' && arguments[1][1] == '\0')
{
arguments[1] = get_environ("OLDPWD");
if (!arguments[1])
{
write(STDERR_FILENO, &"cd: OLDPWD not set\n", 19);
return (EXIT_FAILURE);
}
}
_oldpwd = get_environ("PWD");
set_env("OLDPWD", _oldpwd);
if (chdir(arguments[1]) != 0)
{
perror("cd");
return (EXIT_FAILURE);
}
else
{
/*Update the PWD environment variable*/
new_pwd = getcwd(NULL, 0);
if (new_pwd != NULL)
{
set_env("PWD", new_pwd);
free(new_pwd);
return (EXIT_SUCCESS);
}
}
return (EXIT_SUCCESS);
}
