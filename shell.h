#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 80
#define MAX_ARGV 10

extern char **environ;

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void print_environment(char **environ);
int _getline(char **line, int *len);
char *_strtok(char *str, const char *delimiters);

#endif
