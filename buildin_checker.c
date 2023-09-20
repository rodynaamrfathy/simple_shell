#include "shell.h"
/**
 * _exit - check that argument[0] = exit
 * exit with argument[1] if exists
 * @str: input string to shell
 * @args: splitted string acc to breaks
 * @paths: splitted path from environment
 * @st: status of execution
 * @p: number of proccess
 * @pth: the program path
 * Return: zero if found exit but not true
 * one if not found
 */
int ch_exit(char **args, char *str, char **paths, int *st, char *pth, int p)
{
char *mas = NULL;
int arg_result;
if (_strcmp("exit", args[0]) == 0)
{
if (args[1])
{
if (ch_pov(args[1]) == 0)
{
arg_result = _atoi(args[1]);
_freeall(args, str, paths);
free_array(environ);
exit(arg_result);
}
else
{
mas = _str_concat("Illegal number", args[1]);
_execve_err(mas, args[0], p, pth);
free(mas);
*st = 2;
return (0);
}
}
_freeall(args, str, paths);
free_array(environ);
exit(*st);
}
return (1);
}

/**
 * _buildin - check the builtin environments
 * @arguments: splitted string acc to breaks
 * Return: -1 if not builtin else return builtin function
 */

int _buildin(char **arguments)
{
/*list of builtin environments to compare with argument[0]*/
char *buildin_s[] = {"env", "setenv", "unsetenv", "cd"};
/*pointers to builtin functions*/
int (*buildin_func[])(char **) = {&_printenv,
&setenv_var, &unsetenv_var, &_cdd};
int i;
/*length of builtin functions*/
int _num_buildins = (sizeof(buildin_s) / sizeof(char *));

for (i = 0; i < _num_buildins; i++)
{
if (_strcmp(arguments[0], buildin_s[i]) == 0)
{
return ((*buildin_func[i])(arguments));
}
}
return (-1);
}
