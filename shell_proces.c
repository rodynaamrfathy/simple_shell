#include "shell.h"

/**
 * se - core of shell programe process
 * @str: input string to shell
 * @args: splitted string acc to breaks
 * @paths: splitted path from environment
 * @p_cnt: number of proccess
 * @p_path: the program path
 * @st: status of execution
 * Return: status of execution
 */
void se(char *str, char **args, char **paths, int p_cnt, char *p_path, int *st)
{
char *_breaks = " ";
char *_clean_string;
_clean_string = cleanString(str);
/*check \n && comment(#)*/
if (_clean_string == NULL)
{
free(str);
*st = 0;
return;
}
args = _split(str, _breaks);
if (args[0] == NULL)
{
_freeall(args, str, NULL);
*st = 0;
return;
}
if (ch_exit(args, str, paths, st, p_path, p_cnt) != 0)
{
/* builtin checker */
*st = _buildin(args);
if (*st == -1)
{
before_execution(args, paths, p_cnt, p_path, st);
}
}

_freeall(args, str, NULL);
}
