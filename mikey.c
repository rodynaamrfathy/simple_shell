#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 80
#define MAX_ARGS 10

int main() {
    char line[MAX_LINE_LENGTH];
    char* args[MAX_ARGS];
    int status;

    while (1) {
        printf("$ ");
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            if (feof(stdin)) {
                // Ctrl+D was pressed, exit the shell
                printf("[Disconnected...]\n");
                exit(0);
            }
            else {
                perror("fgets failed");
                exit(1);
            }
        }

        // tokenize the input
        int i = 0;
        args[i] = strtok(line, " \n");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " \n");
        }
        args[i] = NULL;

        // handle built-in commands
        if (strcmp(args[0], "cd") == 0) {
            chdir(args[1]);
            continue;
        }
        else if (strcmp(args[0], "exit") == 0) {
            	 printf("[Disconnected...]\n");
		exit(0);
        }

        // create a child process and execute the command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        }
        else if (pid == 0) {
            // child process
            char* path = "/bin/";
            size_t path_len = strlen(path);
            char full_path[MAX_LINE_LENGTH];
            strncpy(full_path, path, path_len);
            strncpy(full_path + path_len, args[0], MAX_LINE_LENGTH - path_len);
            execve(full_path, args, NULL);
            perror("execve failed");
            exit(1);
        }
        else {
            // parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
