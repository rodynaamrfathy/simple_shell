char *custom_getline(void) {
    char *line = NULL;
    size_t buffer_size = 0;
    ssize_t line_size = getline(&line, &buffer_size, stdin);

    if (line_size == -1) {
        // An error occurred or end of input
        free(line);
        return NULL;
    }

    // Remove the newline character, if present
    if (line[line_size - 1] == '\n') {
        line[line_size - 1] = '\0';
        line_size--;
    }

    // Resize the allocated memory to fit the exact line size
    line = realloc(line, line_size);

    return line;
}
