#include "shell.h"

/**
 * _shell - this function calls fork and execve
 *
 * Return: nothing
 */
void _shell(void)
{
		child_pid = fork();
                if (child_pid == -1)
                {
                        perror("fork");
                        break;
                }
                else if (child_pid == 0)
                {
                        snprintf(command_path, sizeof(command_path), "/usr/bin/%s", argv[0]);
                        execve(command_path, argv, environ);
                        perror("execve failed");
                        exit(1);
                }
                else
                {
                        waitpid(child_pid, &status, 0);
                }
}
