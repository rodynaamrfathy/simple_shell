#include "shell.h"
/**
 * print_num - recursive function to print a number
 *@n: number to print
*/
void print_num(unsigned int n)
{
char c;

if (n / 10)
print_num(n / 10);

c = n % 10 + '0';
write(STDERR_FILENO, &c, 1);
}
/**
 * ch_pov - function to check positive numbers
 *@str: string to check if have number
* Return: zero if positive number
*/
int ch_pov(char *str)

{
int i = 0;

while (str && *str)
{
i = *str - '0';
if (!(i >= 0 && i <= 9))
{
return (EXIT_FAILURE);
}
str++;
}
return (EXIT_SUCCESS);
}
