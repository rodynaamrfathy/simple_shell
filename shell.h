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

/* include system enviroment */
extern char **environ;

/* text edit functions */
size_t custom_strlen(const char *str);
int _snprintf(char *str, size_t size, char *str1, char *str2);
int _putchar(char c);
void _sprintf(char *str);
char *_strtok(char *str, const char *delimiters);
int _strcmp(char *str1, char *str2);

/* functions to handle special commands */
void _argv(char ***argv, char *line);
void print_environment(char **environ);
void cdd(char *argv[], char previous_directory[], size_t prev_directory_size);

/* built-in functions */
void _shell(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _getline(char **line, int *len);

#endif
