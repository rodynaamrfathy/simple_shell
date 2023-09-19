#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    pid_t child_pid;

    while (1) {
        printf("#cisfun$ ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            /* Handle end of file (Ctrl+D) */
            printf("\n");
            break;
        }

        /* Remove the newline character from the input */
        input[strlen(input) - 1] = '\0';

        child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            /* This code runs in the child process */
            if (execlp(input, input, NULL) == -1) {
                perror(input);
                exit(EXIT_FAILURE);
            }
        } else {
            /* This code runs in the parent process */
            int status;
            waitpid(child_pid, &status, 0);
        }
    }

    return 0;
}
