#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;
int infloop(char *program_path);

void se(char *str, char **args, char **paths, int p_cnt, char *p_path,
int *st);

int full_path(char *argument);
char *small_path(char *argument, char **path);

int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strconcat(char *str1, char *str2);
char *_strcopy(char *str);
void rm_comment(char *str);

char **_split(char *string, char *breaks);
int _atoi(char *s);
char *cleanString(char *str);
ssize_t _getline(char **string, size_t *string_size);

char *_str_concat(char *str1, char *str2);

char **get_path(void);
char *get_environ(char *string);

void before_execution(char **args, char **paths, int p_cnt, char *p_path, int *st);
void execution(char **arguments, int *st);

char **copy_array(char **str);
void free_array(char **array);
void rem_index(int idx, char **array);

int ch_exit(char **args, char *str, char **paths, int *st,
char *pth, int p);
int _buildin(char **arguments);

int setenv_var(char **arguments);
int unsetenv_var(char **arguments);
int _cdd(char **arguments);
int _printenv(char **arguments);

void _freeall(char **arguments, char *string, char **paths);

void _execve_err(char *msg, char *command, int count, char *p_path);

void print_num(unsigned int n);
int ch_pov(char *str);
int set_env(char *key, char *value);

#endif
