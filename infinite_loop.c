#include "shell.h"
/**
 * _catch_signal - signal handler
 * @number: the number of signal
 */
void _catch_signal(int number)
{
if (number == SIGINT)
{
write(STDOUT_FILENO, "\n ", 1);
exit(EXIT_SUCCESS);
}
}
/**
 * infloop - function to make the shell always open
 * inside the loop we get string, split it and execute it
 * @program_path: the program path
 * Return: status of execution
 */
int infloop(char *program_path)
{
int status = 0;
char **args = NULL;
int pro_counter = 1;
char *str = NULL;
size_t str_size = 0;
char **path = get_path();

signal(SIGINT, _catch_signal);

/*print prompt if user run the program*/
if (isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO, "$ ", 3);
/* if not or get the command from pipe*/
/*it will start execute the command*/
while ((_getline(&str, &str_size)))
{
/* split arguments && execution the commands*/
se(str, args, path, pro_counter, program_path, &status);
pro_counter++;
fflush(stdout);
/*check non interactive mood*/
if (isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO, "$ ", 3);
}
/*check EOF*/
/*the only way you can arrive here with EOF = -1*/
if (isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO, "\n", 1);
_freeall(args, str, path);
free_array(environ);
return (status);
}
