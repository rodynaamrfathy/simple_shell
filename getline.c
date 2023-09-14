#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char *custom_getline(void);

char *custom_getline(void) {
    static char buffer[BUFFER_SIZE];
    static int buffer_index = 0;
    static int buffer_size = 0;

    char *line = NULL;
    int line_index = 0;
    char c;

    while (1) {
        // If the buffer is empty, read more input
        if (buffer_index >= buffer_size) {
            buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            buffer_index = 0;
            if (buffer_size <= 0) {
                // Error or end of input
                break;
            }
        }

        // Read a character from the buffer
        c = buffer[buffer_index++];
        if (c == '\n') {
            // End of line, terminate the string and return
            line[line_index] = '\0';
            break;
        } else {
            // Append the character to the line
            line = realloc(line, (line_index + 1) * sizeof(char));
            line[line_index++] = c;
        }
    }

    return line;
}

int main() {
    printf("Enter a line of text: ");
    fflush(stdout);

    char *line = custom_getline();

    printf("You entered: %s\n", line);

    free(line);

    return 0;
}
