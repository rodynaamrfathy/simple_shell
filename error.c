#include "shell.h"
/**
 * _execve_err - function to print execve error message
 * @msg: the error message
 * @command: the false command that entered
 * @count: the number of proccess
 * @p_path: the path of program
 */

void _execve_err(char *msg, char *command, int count, char *p_path)
{
int str_len;
str_len = _strlen(p_path);
write(STDERR_FILENO, p_path, str_len);
write(STDERR_FILENO, ": ", 2);
print_num(count);
write(STDERR_FILENO, ": ", 2);
str_len = _strlen(command);
write(STDERR_FILENO, command, str_len);
write(STDERR_FILENO, ": ", 2);
str_len = _strlen(msg);
write(STDERR_FILENO, msg, str_len);
write(STDERR_FILENO, "\n", 1);
}
