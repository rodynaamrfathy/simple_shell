#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100



int env_to_array(char *env_array[]);

#endif
