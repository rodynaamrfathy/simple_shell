#include "shell.h"

/**
 * _realloc -  a function that reallocates a memory block using
 * malloc and free.
 * @ptr: pointer to memory allocated by malloc(old_size).
 * @old_size: allocated space for ptr.
 * @new_size: new memory block.
 *
 * Return: return new memory allocation.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int cpy = (new_size < old_size) ? new_size : old_size;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	p = malloc(new_size);
	for  (i = 0 ; i < cpy ; i++)
	{
		*((char *)p + i) = *((char *)ptr + i);
	}

	return (p);
}
