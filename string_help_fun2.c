#include "shell.h"
/**
 * _split - function that split string  into arguments
 * @string: the string to split
 * @breaks: array of breaks characters
 * Return: array of arguments
 */
char **_split(char *string, char *breaks)
{
char *arg;
char **arguments;
int pos = 0, s = _strlen(string);

arguments = malloc((s + 1) * sizeof(char *));
if (!arguments)
{
perror("Error:failed to allocate memory");
exit(EXIT_FAILURE);
}
/*start split the string*/
arg = strtok(string, breaks);
while (arg != NULL)
{
arguments[pos++] = arg;
arg = strtok(NULL, breaks);
/* NULL here meaning that continue in the same string*/
}
/*the final argument should be NULL for execve function*/
arguments[pos] = NULL;
return (arguments);
}

/**
 * _atoi - converts string to int
 * @s: string to convert
 * Description: converts string to int considering all negatives
 * Return: integer
 **/

int _atoi(char *s)
{
int i, value, sign;

value = 0;
sign = 1;

for (i = 0; s[i] != '\0' && !(s[i] >= '0' && s[i] <= '9'); i++)
{
if (s[i] == '-')
sign = sign * -1;
}

for (i = 0; s[i] != 0; i++)
{
if (s[i] >= '0' && s[i] <= '9')
value = value * 10 + sign * (s[i] - '0');
if (value != 0 && !(s[i] >= '0' && s[i] <= '9'))
return (value);
}
return (value);
}
/**
 * cleanString - clean string from new line and comment
 * @str: string from user or pipe to clean
 * Return: NULL if new line or string without comment
 */

char *cleanString(char *str)
{
/* handle new line in begining */
/* handle # in begining */

if (*str == '\n' || *str == '#')
{
return (NULL);
}
str[_strlen(str) - 1] = '\0';
rm_comment(str);
return (str);
}
/**
 * string_realloc - reallocate string
 * @str: pointer of array of character to reallocate
 * @new_size: number of bytes to allocate
 */
void string_realloc(char *str, size_t new_size)
{
char *new_string = NULL;
if (str == NULL)
{
return;
}
new_string = malloc(new_size);
if (new_string == NULL)
{
return;
}
new_string = _strcopy(str);
free(str);
str = new_string;
}
/**
 * _getline - Implement the getline function
 * @string: the string pointer to pass the characters to
 * @string_size: number of bytes that readed
 * Return: the number of bytes read
 */
ssize_t _getline(char **string, size_t *string_size)
{
size_t buffer_size = BUFSIZ, position = 0;
char *buffer = NULL;
char c;
/*handling error*/
if (string == NULL || string_size == NULL)
{
return (-1);
}
buffer = malloc(buffer_size);
if (buffer == NULL)
{
/* Memory allocation error*/
return (-1);
}
while (read(STDIN_FILENO, &c, 1) == 1)
{
if (position >= buffer_size - 1)
{
/*Double the buffer size if it's not enough*/
buffer_size *= 2;
string_realloc(buffer, buffer_size);
}
buffer[position++] = c;
if (c == '\n')
{
break;
}
if (position == 0 && c == EOF)
{
free(buffer);
return (-1);
}
}
buffer[position] = '\0';
*string = buffer;
*string_size = buffer_size;
return (position);
}
