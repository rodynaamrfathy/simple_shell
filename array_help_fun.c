#include "shell.h"

/**
 * free_array - free array of allocated pointers
 * @array: array of pointers
 */
void free_array(char **array)
{
char **tem = array;

while (array && *array)
{
free(*array);
array++;
}
free(tem);
}

/**
 * copy_array - hard copy
 * @str: array of strings
 * Return: allocated new copy array
 */
char **copy_array(char **str)
{
char **newarr = NULL;
int i = 0;

while (str[i])
{
i++;
}
newarr = malloc(sizeof(char *) * (i + 1));
i = 0;
while (str[i])
{
newarr[i] = _strcopy(str[i]);
i++;
}
newarr[i] = NULL;
return (newarr);
}
/**
 * rem_index - remove element from array
 * @idx: index of element
 * @array: array to remove element from
 */
void rem_index(int idx, char **array)
{
int l = idx;
int len = 0;
while (array && array[len])
{
len++;
}
len++;
free(array[l]);
for (; l < (len - 1); l++)
{
array[l] = array[l + 1];
}
}
