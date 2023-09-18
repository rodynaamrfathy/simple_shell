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

void _sprintf(char *str);
void _shell(char *argv[]);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void print_environment(char **environ);
int _getline(char **line, int *len);
char *_strtok(char *str, const char *delimiters);
int _strcmp(char *str1,char *str2);
void cdd(char *argv[], char previous_directory[], size_t previous_directory_size);

#endif
