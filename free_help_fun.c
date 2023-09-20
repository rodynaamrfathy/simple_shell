#include "shell.h"
/**
 * _freeall - free all memory from arguments & string & paths
 * @string: input string to shell
 * @arguments: splitted string acc to breaks
 * @paths: splitted path from environment
 */
void _freeall(char **arguments, char *string, char **paths)
{
free(string);
free(arguments);
free_array(paths);
}
